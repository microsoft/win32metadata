//*******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
//*******************************************************************************

/*
The following file describes the public interface credential providers must adhere to
if the provider is implemented in a DLL.

The Windows debugger infrastructure has been updated to assist symbols or sources files download when the server returns
an error HTTP_STATUS_DENIED 401 (access denied). In such case the request has to be resent with updated authentication headers
containing proper credentials for the user.

The bridge between the debugger and the credential providers is DbgCredentialProvider.dll. It will look for credential providers using the following algorithm:

    1) It searches and opens a file DbgCredentialProvider.config.xml as follows in the specified order (once the file is found the search terminates):
        a) Tries to locate the DbgCredentialProvider.config.xml file in the folder specified in DBG_COMMON_FOLDER environment variable (if any).
        b) Tries to locate the DbgCredentialProvider.config.xml file in %LOCALAPPDATA%\Dbg\Common folder.
        c) Tries to locate the DbgCredentialProvider.config.xml file in the folder of the calling application.
        d) Tries to locate the DbgCredentialProvider.config.xml file in the folder next to DbgCredentialProvider.dll.

            The DbgCredentialProvider.config.xml file contains a folders list:

                 <?xml version="1.0" encoding="utf-8"?>
                 <!--
                 The config file is located next to DbgCredentialProvider.dll.
                 -->
                 <Settings>
                     <Folders>
                         <!--
                             This is a list of the folders which should be provided as an absolute file path or
                             relative to the location of this config file.
                         -->
                         <Folder>CredentialProviders</Folder>
                     </Folders>
                     <!-- <CredentialProviders>

                        Please see the explanations for those in the XML section below. Those here have the same meaning.

                     </CredentialProviders> -->
                 </Settings>

                 You can list more than one folder under <Folders></Folders> elements. The folders can be relative or absolute path. If it is relative path, it is relative to the location
                 of the DbgCredentialProvider.config.xml file. The folders will be searched for providers in the order listed in the XML file.

                 In the current example the Folders collection has just one folder "CredentialProviders" and it is a relative path.

                 Optionally you can also include <CredentialProviders> element, and it is same as discussed in the following section where the
                 xml files are explained.

    2) Then all files with extension '*.xml' in CredentialProviders folder will be enumerated. The order in which the XML files are enumerated is unspecified. Those XML files describe which
       debugger credential providers are available for the debugger. You may find DbgCredentialProvider_gcmw.xml file (or other XML files) in CredentialProvider folder which contain data like this:

                 <?xml version="1.0" encoding="utf-8"?>
                 <CredentialProviders>
                     <!--
                           This is a list of the provider modules which should be provided as an absolute file path or
                           relative to the location of this config file.
                           The provider is a DLL, EXE or CMD file.
                     -->
                   <CredentialProvider ApiVersion="2.0.0">GCMW\DbgCredentialProvider_gcmw.dll</CredentialProvider>

                 </CredentialProviders>

       The XML file may list more than one credential provider. In this example we have just one provider DbgCredentialProvider_gcmw.dll and it is located
       in GCMW folder relative to the DbgCredentialProvider_gcmw.xml file location. The providers may be relative or absolute paths similar to the ones described
       in the section for DbgCredentialProvider.config.xml file.

The debugger credential providers can be DLL, EXE or CMD script files. The debugger will ask every provider for credentials and it will use the credentials from the first provider
which returns success.

If the provider is implemented in a DLL it must export GetUserCredentials method as listed in this file.
If the provider is implemented in EXE or a CMD script it should be able to process the following command line parameters (case insensitive), which cannot be combined with each other.
    - Get
    - Erase
    - Store

    Get Command
    It is used to retrieve a credential. The remaining data will be passed to the provider via the standard input stream:

        protocol=https or http. For security reasons we recommend you send credentials only over https.
        host=XXX ex. host=contoso.symbols.com
        path=YYY ex. path=apis/symbol/symsrv
        resourceKind=symbols or sources. Ex resourceKind=symbols
        isretry=true or false 
        issilent=true or false
        parenthwnd=ZZZ ex. parenthwnd=593598
        <Followed by an empty line to indicate the end of the input data>

        The full URI/URL is built by concatenating <protocol>://<host>/<path> from above i.e. it is
                https://contoso.symbols.com/apis/symbol/symsrv

        The return data to the debugger is via the standard output stream as follows:

        username=xxx
        credentialkind=Basic
        password=yyy --> This can be a password or a PAT token

        Or 

        username=xxx
        credentialkind=Bearer
        header=Bearer <TOKEN_GOES_HERE> ---> Usually OAuth2 tokens begin with "ey" and it is a very long string

        Error may be returned via 

        error=zzzzz

        For example for the symbol server https://contoso.symbols.com/apis/symbol/symsrv the request would look like this:

        protocol=https
        host=contoso.symbols.com
        path=apis/symbol/symsrv
        resourceKind=symbols
        isretry=false 
        issilent=false
        parenthwnd=593598
        Followed by an empty line to indicate the end of the input data.

    Please note that the parameters above (or in the resulting output stream below) are not case sensitive.

    The debugger asks for the credential using isRetry=false. Some providers may be getting the token from their local cache. Once the debugger resends the HTTP request
    with this token the server may return 401 response again. This may be due to the token has expired. Then the debugger will ask the credential provider for a new token
    and this time the isRetry=true. In such case the provider should not use its cache but retrieve a brand new token.

    Some providers may display an authentication UI. If so it should use the 'parenthwnd' parameter so this UI would appear as a modal dialog to the main debugger window.
    Otherwise the authentication UI may be hidden behind the main debugger window and the user may be given the impression that the debugger is "frozen".

    A debugger client application similar to windbg may use may use DBG_CREDENTIAL_PROVIDER_PARENT_HWND environment variable or imagehlp/dbghelp SymSetParentWindow method to setup the parent HWND.
    You can also use IDebugAdvanced2::Request message DEBUG_REQUEST_SET_PARENT_HWND with value of HWND cast to UINT32.

    In some non-interactive environments there may be no user to interact with a UI. In such a case the parameter issilent would be true.
    The provider should not be displaying any authentication or other UI when this parameter is true.

    How to setup the silent (non interactive) environment is described below:
           a) SYMOPT_NO_PROMPTS described in this document https://learn.microsoft.com/windows-hardware/drivers/debugger/symbol-options.
           b) SSRVOPT_UNATTENDED described in this document https://learn.microsoft.com/previous-versions/ff797954(v=vs.85)
           c) IDebugSymbols::SetSymbolOptions described in this document https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setsymboloptions
           d) From the Windows debugger you can execute the following bang command "!sym quiet" (or "!sym prompts off")

    Store Command
        The credential provider may choose to use this command to store the credentials into its cache. The input parameters are same as for Get command.
        There is no output return value needed (Error still might be returned)

    Erase Command
        The credential provider may choose to use this command to erase the credentials from its cache. The input parameters are same as for Get command.
        There is no output return value needed (Error still might be returned)

    Here is an example of a CMD file which returns an HTTP authentication header:

         OAuth2CredentialProvider.xml file located in CredentialProviders folder:

             <?xml version="1.0" encoding="utf-8"?>
             <CredentialProviders>
                 <CredentialProvider ApiVersion="2.0.0" >OAuth2CredentialProvider\OAuth2CredentialProvider.cmd</CredentialProvider>
             </CredentialProviders>	

         OAuth2CredentialProvider.cmd file located in OAuth2CredentialProvider folder:

             @echo off
             echo username=UserName@domain.com
             echo header=Bearer <TOKEN_GOES_HERE>

   Here is a PS script example of returning a PAT token:

         File PatCredentialProvider.xml content:

             <?xml version="1.0" encoding="utf-8"?>
             <CredentialProviders>
                 <CredentialProvider ApiVersion="2.0.0">PATCredentialProvider\PATCredentialProvider.bat</CredentialProvider>
             </CredentialProviders>

         File PATCredentialProvider.bat located in PATCredentialProvider folder:

             @echo off
             <PATH_TO_POWERSHELL>\PowerShell.exe -NoProfile -executionpolicy Unrestricted -WindowStyle Hidden -File "%~dp0\PATCredentialProvider.ps1"

         File PATCredentialProvider.ps1 located in PATCredentialProvider folder:

             <#
            .SYNOPSIS
               Given input, parses to find out which symbol server we want credentails for, and searches the Microsoft Credential Manager for those credentials.
               If found, prints the credentials to standard output. If not, prints error.

            .INPUT
               Delivered through standard input:
               protocol=http or https
               host=xxx ex. host=contoso.symbols.com
               path=yyy ex. path=apis/symbol/symsrv
               resourceKind=symbols
               isretry=false 
               issilent=false
               parenthwnd=593598
               <empty line to mark the end of the input parameters>

            .OUTPUT

               Delivered through standard output:

               username=aaa
               password=bbb - where the password can be a password or PAT. When PAT is returned the username will be any name (not necessarily the name of the currently logged in user)<!--[SuppressMessage("Microsoft.Security", "CS001:SecretInline", Justification="It's an example")]-->
               <empty line to mark the end of the output parameters>

            #>

            $logDirectory = (Get-Item Env:LoggingDirectory).Value
            $logFile = Join-Path $logDirectory "credProviderLog.txt"

            try
            {
               "Entering Credential Provider" | Out-File $logFile -Append

               $lines = While($line=Read-Host) {$line}
               $lines | Out-File $logFile -Append
               if (!(Get-Module "CredentialManager"))
               {
                   "Installing module" | Out-File $logFile -Append

                   Install-PackageProvider -Name NuGet -MinimumVersion 2.8.5.201 -Force

                   Install-Module CredentialManager -force -Scope CurrentUser
               }

               $pathLine = $lines | Where-Object {$_.StartsWith("path=")} | Select-Object -First 1
               "Found path line: $pathLine" | Out-File $logFile -Append

               [regex]$regex="path=(?<ServerName>.*)"
               $pathLine -Match $regex

               $symbolPath = "symbol:$($Matches.ServerName)"

               "Found symbol path: $symbolPath" | Out-File $logFile -Append

               $PAT = Get-StoredCredential -Target $symbolPath -AsCredentialObject

               if ($PAT)
               {
                   "Found PAT!" | Out-File $logFile -Append
                   Write-Host "username=placeholder"
                   Write-Host "password=$($PAT.Password)"; # For OAuth 2 tokens You can change to output header=Bearer TOKEN
                   Write-Host
               }
               else
               {
                   "Could not locate PAT for Symbol Server: $symbolPath" | Out-File $logFile -Append
                   Write-Host "error=Could not locate PAT for Symbol Server: $symbolPath"
               }
            }
            catch [System.SystemException]
            {
               "ERROR" | Out-File $logFile -Append
            
               $_ | Out-File $logFile -Append
            }

If you are writing a custom provider located in a CMD or EXE file, you can test it simply by launching it from a console window using the commands.
For example:

DebuggerCredentialManager.exe get

    This would start the application, and print something like this and then will wait for user input (an empty line indicates end of the user input).

[Information] [DebuggerCredentialProvider.102949]Microsoft Debugger Credential Manager version 2024.0409.02656.285 (Windows, .NET 6.0.29) 'get'

Please note that the providers may chose to print some diagnostic information on the output stream, but the debugger would ignore it, nor it will
display those to the user. So the examples of extra information printed here are for illustration purposes only. Other providers may print
other diagnostic information or not print anything.

Here is the information you enter (it can be any text case) in the console window (input stream):

protocol=https
host=contoso.symbols.com
path=apis/symbol/symsrv
resourceKind=symbols
isretry=false 
issilent=false
parenthwnd=593598
Then press ENTER key twice to indicate end of user input.

The provider responds via the standard output stream.
The debugger will ignore any lines not matching the pattern `key=value` where key is
one of the following: protocol, host, path, username, credentialkind,or header.
Case is ignored in the key. The debugger treats a blank line as the end of input.

[Verbose] [DebuggerCredentialProvider.103258]AzureCredentialProvider - Attempting to acquire bearer token using provider 'Msal Cache'
[Verbose] [DebuggerCredentialProvider.103300]Token expiration data - current UTC time:9/18/2024 5:33:00 PM, ExpiresOn: 9/18/2024 6:43:25 PM
[Information] [DebuggerCredentialProvider.103300]AzureCredentialProvider - Acquired bearer token using 'Msal Cache'
protocol=https
host=contoso.symbols.com
path=apis/symbol/symsrv
username=UserName@domain.com
credentialkind=Bearer
header=Bearer eyJ0eXAi....
<empty line>

The remaining section of the file defines the interface signature of GetUserCredentials method which should be exported by credential providers implemented as a DLL file.

*/

namespace Debugger::CredentialProvider::Provider
{
enum class MessageErrorLevelKind : uint8_t
{
    Info = 0,
    Warning,
    Error,
};

// The caller of this method should not terminate the message with '\r' or '\n' characters
// (which makes this method with semanthic similar of PrintLine)
typedef void (*DbgPrintMessageFn)(_In_ MessageErrorLevelKind errorLevel, _In_ PCWSTR message);

struct GetUserCredentialsRequest
{
    LPCWSTR Protocol;      // The full request URL can be built from Protocol, Host and Path as follows:
    LPCWSTR Host;          // Protocol://Host/Path
    LPCWSTR Path;          // The caller/debugger will make sure Path never starts with '/' character
    LPCWSTR ResourceKind;  // It can be "symbols", "sources", etc.
                           // The credential provider implementation may use this to adjust
                           // the required permissions when acquiring credentials. It also may be used
                           // to cache credentials for future use.
    bool Interactive;      // true - display UI is ok, false - no UI.
                           // Please refer to the explanations above on how to setup a non interactive environment
    bool IsRetry;          // When true the provider may skip reading the caches and get new credentials
    HWND ParentHwnd;       // The parent HWND if an authentication UI is displayed.
                           // The applications can use DBG_CREDENTIAL_PROVIDER_PARENT_HWND environment variable
                           // or imagehlp/dbghelp SymSetParentWindow method to setup the parent HWND.

    DbgPrintMessageFn PrintMessageFn;
};

enum CredentialResponseResultKind
{
    Success = 0,
    NoProviders, // There are no installed providers or can't launch 3rd party provider
    ProviderNotApplicable, // the provider can't handle requests to the provided URL
    Error
};

class GetUserCredentialsResponse final
{
public:

    CredentialResponseResultKind Result = CredentialResponseResultKind::Error;
    BSTR UserName = nullptr;
    BSTR Password = nullptr;
    BSTR HttpAuthenticationHeader = nullptr;
    BSTR ErrorMessage = nullptr;

    GetUserCredentialsResponse() = default;

    GetUserCredentialsResponse(GetUserCredentialsResponse const&) = delete;
    GetUserCredentialsResponse& operator=(GetUserCredentialsResponse const&) = delete;

    GetUserCredentialsResponse(GetUserCredentialsResponse&& other) noexcept
    {
        Result = other.Result;
        UserName = other.UserName;
        Password = other.Password;
        HttpAuthenticationHeader = other.HttpAuthenticationHeader;
        ErrorMessage = other.ErrorMessage;

        other.Release();
    }

    GetUserCredentialsResponse& operator=(GetUserCredentialsResponse&& other) noexcept
    {
        if (this != addressof(other))
        {
            Clear();

            Result = other.Result;
            UserName = other.UserName;
            Password = other.Password;
            HttpAuthenticationHeader = other.HttpAuthenticationHeader;
            ErrorMessage = other.ErrorMessage;

            other.Release();
        }
        return (*this);
    }

    ~GetUserCredentialsResponse()
    {
        Clear();
    }

    void Clear()
    {
        SecureSysFreeString(UserName);
        SecureSysFreeString(Password);
        SecureSysFreeString(HttpAuthenticationHeader);
        SecureSysFreeString(ErrorMessage);
    }

private:
    template <class _Tp>
    _Tp* addressof(_Tp& __x) noexcept
    {
        return reinterpret_cast<_Tp*>(
            const_cast<char*>(&reinterpret_cast<const volatile char&>(__x)));
    }

    void Release() noexcept
    {
        Result = CredentialResponseResultKind::Error;
        UserName = nullptr;
        Password = nullptr;
        ErrorMessage = nullptr;
        HttpAuthenticationHeader = nullptr;
    }

    void SecureSysFreeString(_Inout_ BSTR& bstrString)
    {
        if (bstrString != nullptr)
        {
            size_t const length = wcslen(bstrString);
            SecureZeroMemory(bstrString, length * sizeof(wchar_t));
            SysFreeString(bstrString);
            bstrString = nullptr;
        }
    }
};

// The caller (debugger) of this method will provide the request and response parameters.
// The caller will ensure that the UserName, Password and ErrorMessage are nullptr upon method entry.
// The implementation should fill UserName, Password, ErrorMessage (optionally), and Result.
//
HRESULT WINAPI GetUserCredentials(_In_ GetUserCredentialsRequest const & request,
                                  _Inout_ GetUserCredentialsResponse * pResponse);

}

