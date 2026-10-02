use std::path::Path;

const GLOBAL_DEFINES: &str = "\
#define MICROSOFT_WINDOWS_WINBASE_H_DEFINE_INTERLOCKED_CPLUSPLUS_OVERLOADS 0
#define CERT_CHAIN_PARA_HAS_EXTRA_FIELDS
#define SCHANNEL_USE_BLACKLISTS
#define QCC_OS_GROUP_WINDOWS
";

const COMPATIBILITY_SHIMS: &str = r#"
typedef NTSTATUS* PNTSTATUS;
typedef LPVOID* PPVOID;
typedef UCHAR KIRQL;
typedef struct _OLD_LARGE_INTEGER {
    ULONG LowPart;
    LONG HighPart;
} OLD_LARGE_INTEGER, *POLD_LARGE_INTEGER;
#define _NTDEF_
"#;

const AUTHORITY_SATELLITE_PARTITIONS: &[&str] = &[
    "DirectDraw",
    "Display",
    "HtmlHelp",
    "IO",
    "MsChap",
    "Printing",
];

const AUTHORITY_SATELLITE_HEADERS: &[&str] = &["vfw.h", "xamlOM.h"];

pub fn main_prefix(prelude: &str, structured_storage_header: &Path) -> Result<String, String> {
    let mut source = String::from(GLOBAL_DEFINES);
    source.push_str(prelude);
    append_security_seed(&mut source);

    append_headers(
        &mut source,
        &[
            "comsvcs.h",
            "combaseapi.h",
            "eventsys.h",
            "comadmin.h",
            "mtxdm.h",
        ],
    );
    append_com_structured_storage(&mut source, structured_storage_header)?;
    append_identity(&mut source);
    append_internet_explorer(&mut source);
    append_ip_helper(&mut source);
    append_direct_draw_prerequisites(&mut source);
    append_d3d9_prerequisites(&mut source);
    append_direct_show(&mut source);
    append_media_foundation(&mut source);
    append_rras(&mut source);
    append_winprog(&mut source);
    Ok(source)
}

pub fn append_threading_input(source: &mut String, threading_input: &Path) -> Result<(), String> {
    let threading_input = quoted_include_path(threading_input, "Threading aggregate input")?;

    source.push_str("\n#pragma push_macro(\"MakeProcThreadAttributeConst\")\n");
    source.push_str("#pragma push_macro(\"ProcThreadAttributeValue\")\n");
    source.push_str(&format!("#include \"{threading_input}\"\n"));
    source.push_str("#pragma pop_macro(\"ProcThreadAttributeValue\")\n");
    source.push_str("#pragma pop_macro(\"MakeProcThreadAttributeConst\")\n");
    Ok(())
}

fn quoted_include_path(path: &Path, description: &str) -> Result<String, String> {
    let path = path
        .to_str()
        .ok_or_else(|| {
            format!(
                "{description} path is not valid Unicode: {}",
                path.display()
            )
        })?
        .replace('\\', "/");
    if path.contains('"') {
        return Err(format!("{description} path contains a quote: {path}"));
    }
    Ok(path)
}

pub fn satellite_source(prelude: &str) -> String {
    let mut source = format!("{GLOBAL_DEFINES}{prelude}");
    append_direct_draw_prerequisites(&mut source);
    append_headers(&mut source, &["dxmini.h", "dmemmgr.h"]);
    append_d3d9_prerequisites(&mut source);
    append_headers(
        &mut source,
        &["winnt.h", "winerror.h", "dxcore.h", "dxcore_interface.h"],
    );
    append_display(&mut source);
    append_html_help(&mut source);
    append_io(&mut source);
    append_extern_c_headers(&mut source, &["mschapp.h"]);
    append_printing(&mut source);
    source
}

pub fn psapi_source(prelude: &str, version: u8) -> String {
    format!(
        "{GLOBAL_DEFINES}{prelude}\n#undef PSAPI_VERSION\n#define PSAPI_VERSION {version}\n#include <psapi.h>\n"
    )
}

pub fn is_satellite_header(path: &Path) -> bool {
    path.file_name()
        .and_then(|name| name.to_str())
        .is_some_and(|name| {
            crate::win32_headers::SATELLITE_HEADERS
                .iter()
                .any(|candidate| name.eq_ignore_ascii_case(candidate))
        })
}

pub fn uses_satellite_environment(identity: &str) -> bool {
    AUTHORITY_SATELLITE_PARTITIONS
        .iter()
        .any(|candidate| identity.eq_ignore_ascii_case(candidate))
}

pub fn is_authority_satellite_header(path: &Path) -> bool {
    is_satellite_header(path)
        || path
            .file_name()
            .and_then(|name| name.to_str())
            .is_some_and(|name| {
                AUTHORITY_SATELLITE_HEADERS
                    .iter()
                    .any(|candidate| name.eq_ignore_ascii_case(candidate))
            })
}

pub fn is_psapi_header(path: &Path) -> bool {
    path.file_name()
        .and_then(|name| name.to_str())
        .is_some_and(|name| name.eq_ignore_ascii_case("psapi.h"))
}

fn append_com_structured_storage(
    source: &mut String,
    structured_storage_header: &Path,
) -> Result<(), String> {
    append_headers(
        source,
        &[
            "wtypes.h",
            "objidl.h",
            "ole2.h",
            "objbase.h",
            "combaseapi.h",
            "propvarutil.h",
            "propidl.h",
            "propidlbase.h",
            "coml2api.h",
            "propapi.h",
        ],
    );
    let structured_storage_header = quoted_include_path(
        structured_storage_header,
        "Structured Storage aggregate header",
    )?;
    source.push_str(&format!("#include \"{structured_storage_header}\"\n"));
    Ok(())
}

fn append_security_seed(source: &mut String) {
    append_headers(source, &["winsock2.h", "IPExport.h"]);
    source.push_str(
        "\n#define PIO_APC_ROUTINE_DEFINED\n\
         #include <winternl.h>\n\
         #include <icmpapi.h>\n\
         #undef PIO_APC_ROUTINE_DEFINED\n",
    );
    source.push_str(COMPATIBILITY_SHIMS);
    append_headers(source, &["NTSecAPI.h", "sspi.h", "wincred.h", "NTSecPKG.h"]);
    append_extern_c_headers(source, &["schannel.h"]);
}

fn append_direct_draw_prerequisites(source: &mut String) {
    append_headers(
        source,
        &["ddraw.h", "ddrawi.h", "ddrawint.h", "ddkernel.h", "dvp.h"],
    );
}

fn append_d3d9_prerequisites(source: &mut String) {
    append_headers(source, &["d3d9.h", "d3d9types.h", "d3d9caps.h"]);
}

fn append_display(source: &mut String) {
    source.push_str(
        "\n#define IN _In_\n\
         #define OUT _Out_\n",
    );
    append_headers(
        source,
        &["winnt.h", "winddi.h", "devpropdef.h", "ntddvdeo.h"],
    );
    source.push_str("\n#define USERMODE_DRIVER\n#include <winddi.h>\n#undef USERMODE_DRIVER\n");
}

fn append_html_help(source: &mut String) {
    source.push_str(
        "\n#ifdef _ARM64_\n\
         #pragma push_macro(\"InterlockedIncrement\")\n\
         #pragma push_macro(\"InterlockedDecrement\")\n\
         #undef InterlockedIncrement\n\
         #undef InterlockedDecrement\n\
         #define InterlockedIncrement(x) 0\n\
         #define InterlockedDecrement(x) 0\n\
         #endif\n",
    );
    append_headers(source, &["htmlhelp.h", "infotech.h"]);
    source.push_str(
        "\n#ifdef _ARM64_\n\
         #pragma pop_macro(\"InterlockedDecrement\")\n\
         #pragma pop_macro(\"InterlockedIncrement\")\n\
         #endif\n",
    );
}

fn append_identity(source: &mut String) {
    append_headers(
        source,
        &[
            "winnt.h",
            "winbase.h",
            "securitybaseapi.h",
            "subauth.h",
            "tokenbinding.h",
            "security.h",
            "slpublic.h",
            "issper16.h",
            "ccgplugins.h",
            "schnlsp.h",
            "slerror.h",
            "sliddefs.h",
            "wdigest.h",
            "sas.h",
        ],
    );
}

fn append_internet_explorer(source: &mut String) {
    append_headers(
        source,
        &[
            "docobjectservice.h",
            "downloadmgr.h",
            "exdispid.h",
            "extensionvalidation.h",
            "homepagesetting.h",
            "htiframe.h",
            "htiface.h",
            "ie12plugin.h",
            "ieautomation.h",
        ],
    );
    append_extern_c_headers(source, &["ieobj.h", "iepmapi.h"]);
    append_headers(
        source,
        &[
            "iewebdriver.h",
            "iextag.h",
            "inetreg.h",
            "inetsdk.h",
            "idispids.h",
            "msiehost.h",
            "openservice.h",
            "perhist.h",
            "ratings.h",
            "urlhist.h",
            "webevnts.h",
            "ocmm.h",
            "imgutil.h",
        ],
    );
}

fn append_io(source: &mut String) {
    append_headers(
        source,
        &[
            "mmsystem.h",
            "objbase.h",
            "ObjIdl.h",
            "combaseapi.h",
            "winbase.h",
            "winnt.h",
        ],
    );
    source.push_str("\n#define USERMODE_DRIVER\n#include <winddi.h>\n#undef USERMODE_DRIVER\n");
    append_headers(source, &["winuser.h", "ioapiset.h"]);
}

fn append_ip_helper(source: &mut String) {
    append_headers(
        source,
        &[
            "ip2string.h",
            "ws2def.h",
            "ws2ipdef.h",
            "windns.h",
            "iphlpapi.h",
            "fltdefs.h",
            "ipinfoid.h",
            "inaddr.h",
        ],
    );
}

fn append_direct_show(source: &mut String) {
    append_headers(source, &["d3d9helper.h"]);
    append_headers(
        source,
        &[
            "ks.h",
            "ksmedia.h",
            "vptype.h",
            "gdipluseffects.h",
            "segment.h",
            "bdatypes.h",
            "bdaiface.h",
            "mpeg2psiparser.h",
            "strmif.h",
            "ocidl.h",
            "wingdi.h",
            "camerauicontrol.h",
            "wmcodecdsp.h",
            "windows.devices.midi.h",
            "qnetwork.h",
            "amaudio.h",
            "il21dec.h",
            "amparse.h",
            "control.h",
            "videoacc.h",
            "iwstdec.h",
            "vidcap.h",
            "dshowasf.h",
            "amstream.h",
            "amvideo.h",
            "dmodshow.h",
            "mixerocx.h",
            "mpconfig.h",
            "mpegtype.h",
            "vmr9.h",
            "vpconfig.h",
            "vpnotify.h",
            "amxmlgraphbuilder.h",
            "amva.h",
            "vptype.h",
            "aviriff.h",
            "avifmt.h",
            "dxva9typ.h",
            "mmreg.h",
            "dvdmedia.h",
            "dvdevcod.h",
            "dshow.h",
            "audevcod.h",
            "dxva.h",
            "vfwmsgs.h",
            "evcode.h",
            "errors.h",
            "codecapi.h",
            "mediaobj.h",
            "medparam.h",
            "wmp.h",
            "austream.h",
            "ddstream.h",
            "mmstream.h",
            "activecf.h",
            "dxva.h",
            "dxva2api.h",
            "dxva2swdev.h",
            "evntrace.h",
            "dxva2trace.h",
            "mediaerr.h",
            "mpeg2error.h",
            "pbdaerrors.h",
            "playlist.h",
            "xprtdefs.h",
        ],
    );
}

fn append_media_foundation(source: &mut String) {
    append_headers(source, &["d3d9.h", "d3d9types.h", "d3d9caps.h"]);
    append_headers(
        source,
        &[
            "camerauicontrol.h",
            "d3d11.h",
            "d3d11_1.h",
            "d3d11_4.h",
            "d3d12video.h",
            "wmcodecdsp.h",
            "dxva9typ.h",
            "dxva.h",
            "uuids.h",
            "codecapi.h",
            "dxvahd.h",
            "opmapi.h",
            "mfidl.h",
            "wmcontainer.h",
            "mfobjects.h",
            "mfcaptureengine.h",
            "mfd3d12.h",
            "mfapi.h",
            "mftransform.h",
            "mfmediaengine.h",
            "mfmp2dlna.h",
            "mfreadwrite.h",
            "evr.h",
            "dxva2api.h",
            "mfplay.h",
            "mfsharingengine.h",
            "evr9.h",
            "mfmediacapture.h",
            "mfspatialaudio.h",
            "mfcontentdecryptionmodule.h",
            "mferror.h",
            "mfvirtualcamera.h",
            "opmxbox.h",
            "playto.h",
        ],
    );
}

fn append_printing(source: &mut String) {
    append_headers(
        source,
        &["objbase.h", "BiDiSpl.h", "filterpipeline.h", "msxml6.h"],
    );
    source.push_str("\n#define USERMODE_DRIVER\n#include <winddi.h>\n#undef USERMODE_DRIVER\n");
    append_headers(
        source,
        &[
            "compstui.h",
            "winspool.h",
            "mxdc.h",
            "winddiui.h",
            "printoem.h",
            "prcomoem.h",
            "prdrvcom.h",
            "PrinterExtension.h",
        ],
    );
    append_extern_c_headers(source, &["prnasnot.h"]);
    append_headers(
        source,
        &["prnasntp.h", "prntfont.h", "tcpxcv.h", "usbprint.h"],
    );
    append_extern_c_headers(source, &["winppi.h"]);
    append_headers(
        source,
        &[
            "winsplp.h",
            "xpsrassvc.h",
            "imgerror.h",
            "printerextensiondispid.h",
            "printpreview.h",
        ],
    );
}

fn append_rras(source: &mut String) {
    append_headers(
        source,
        &["ipmib.h", "ras.h", "rasdlg.h", "mprapi.h", "rasshost.h"],
    );
    append_extern_c_headers(source, &["mgm.h"]);
    append_headers(source, &["rtmv2.h", "raserror.h", "inaddr.h"]);
}

fn append_winprog(source: &mut String) {
    append_headers(
        source,
        &[
            "mmsystem.h",
            "wtypes.h",
            "winbase.h",
            "winnt.h",
            "objbase.h",
            "winuser.h",
            "windowsx.h",
            "winternl.h",
            "dbghelp.h",
            "exposeenums2managed.h",
            "camerauicontrol.h",
            "editionupgradehelper.h",
            "featurestagingapi.h",
            "apiquery2.h",
            "dciman.h",
            "ddrawi.h",
        ],
    );
    append_extern_c_headers(source, &["ddrawgdi.h"]);
    append_headers(
        source,
        &[
            "advpub.h",
            "ime.h",
            "winnls32.h",
            "exdisp.h",
            "loadperf.h",
            "capi.h",
            "msxml.h",
            "lmaccess.h",
            "wininet.h",
            "rpcndr.h",
            "aux_ulib.h",
            "stralign.h",
            "tdiinfo.h",
            "appcompatapi.h",
            "dsound.h",
        ],
    );
    append_extern_c_headers(source, &["wldp.h"]);
    append_headers(
        source,
        &[
            "defaultbrowsersyncsettings.h",
            "delayloadhandler.h",
            "deletebrowsinghistory.h",
        ],
    );
}

fn append_headers(source: &mut String, headers: &[&str]) {
    for header in headers {
        source.push_str(&format!("\n#include <{header}>"));
    }
    source.push('\n');
}

fn append_extern_c_headers(source: &mut String, headers: &[&str]) {
    source.push_str("\nextern \"C\" {\n");
    for header in headers {
        source.push_str(&format!("#include <{header}>\n"));
    }
    source.push_str("}\n");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn authority_source_preserves_first_include_constraints() {
        let mut main = main_prefix(
            "#define SECURITY_WIN32\n#include <windows.h>\n",
            Path::new(r"C:\repo\generation\WinSDK\Partitions\Com.StructuredStorage\manual.h"),
        )
        .unwrap();
        append_threading_input(
            &mut main,
            Path::new(r"C:\repo\generation\WinSDK\Partitions\Threading\main.cpp"),
        )
        .unwrap();
        let satellite = satellite_source("#define SECURITY_WIN32\n#include <windows.h>\n");

        let windows = main.find("#include <windows.h>").unwrap();
        assert!(
            main.find("MICROSOFT_WINDOWS_WINBASE_H_DEFINE_INTERLOCKED_CPLUSPLUS_OVERLOADS")
                .unwrap()
                < windows
        );
        assert!(main.find("CERT_CHAIN_PARA_HAS_EXTRA_FIELDS").unwrap() < windows);
        assert!(
            main.find("#define SCHANNEL_USE_BLACKLISTS").unwrap()
                < main.find("#include <schannel.h>").unwrap()
        );
        assert!(
            main.find("#define PIO_APC_ROUTINE_DEFINED").unwrap()
                < main.find("#include <winternl.h>").unwrap()
        );
        assert!(
            main.find("#include <winternl.h>").unwrap()
                < main.find("typedef NTSTATUS* PNTSTATUS").unwrap()
        );
        assert!(
            main.find("typedef NTSTATUS* PNTSTATUS").unwrap()
                < main.find("#define _NTDEF_").unwrap()
        );
        assert!(
            main.find("#define _NTDEF_").unwrap() < main.find("#include <NTSecAPI.h>").unwrap()
        );
        assert!(
            main.find("Com.StructuredStorage/manual.h").unwrap()
                < main.find("Partitions/Threading/main.cpp").unwrap()
        );
        assert!(main.contains("#include <strmif.h>"));
        assert!(main.contains("#include <subauth.h>"));
        assert!(main.contains("#include <avifmt.h>"));
        assert!(main.contains("#include <segment.h>"));
        assert!(!main.contains("#include <winddi.h>"));
        assert!(!main.contains("#include <infotech.h>"));
        assert!(!main.contains("#include <mschapp.h>"));
        assert!(satellite.contains("#include <winddi.h>"));
        assert!(satellite.contains("#include <infotech.h>"));
        assert!(satellite.contains("#include <mschapp.h>"));
        assert!(satellite.contains("#include <dxmini.h>"));
        assert!(satellite.contains("#include <dmemmgr.h>"));
        assert!(!satellite.contains("#include <strmif.h>"));
        assert!(!satellite.contains("#include <subauth.h>"));
        assert!(!satellite.contains("#include <avifmt.h>"));
        assert!(!satellite.contains("#include <segment.h>"));
        assert!(!main.contains("#include <dxmini.h>"));
        assert!(!main.contains("#include <dmemmgr.h>"));

        for source in [&main, &satellite] {
            let ddraw = source.find("#include <ddraw.h>").unwrap();
            let ddrawi = source.find("#include <ddrawi.h>").unwrap();
            let ddrawint = source.find("#include <ddrawint.h>").unwrap();
            let ddkernel = source.find("#include <ddkernel.h>").unwrap();
            let dvp = source.find("#include <dvp.h>").unwrap();
            assert!(ddraw < ddrawi && ddrawi < ddrawint && ddrawint < ddkernel && ddkernel < dvp);
            let d3d9 = source.find("#include <d3d9.h>").unwrap();
            let d3d9types = source.find("#include <d3d9types.h>").unwrap();
            let d3d9caps = source.find("#include <d3d9caps.h>").unwrap();
            assert!(d3d9 < d3d9types && d3d9types < d3d9caps);
        }
        assert!(
            satellite.find("#include <d3d9caps.h>").unwrap()
                < satellite.find("#include <winddi.h>").unwrap()
        );
        assert!(
            main.find("#include <d3d9helper.h>").unwrap() < main.find("#include <vmr9.h>").unwrap()
        );
        assert!(
            main.find("#include <vmr9.h>").unwrap() < main.find("#include <dxva2api.h>").unwrap()
        );
        assert!(
            main.find("#include <dxva2api.h>").unwrap()
                < main.find("#include <dxva2swdev.h>").unwrap()
        );
    }

    #[test]
    fn satellite_classification_is_exact_and_case_insensitive() {
        assert!(is_satellite_header(Path::new(r"C:\sdk\shared\NTDDSTOR.H")));
        assert!(!is_satellite_header(Path::new(r"C:\sdk\um\winuser.h")));
        assert!(!is_satellite_header(Path::new(
            r"C:\repo\Partitions\Threading\main.cpp"
        )));
        assert!(is_psapi_header(Path::new(r"C:\sdk\um\PsApi.h")));
        assert!(!is_psapi_header(Path::new(
            r"C:\sdk\um\processthreadsapi.h"
        )));
        assert!(uses_satellite_environment("Display"));
        assert!(uses_satellite_environment("DirectDraw"));
        assert!(uses_satellite_environment("mschap"));
        assert!(!uses_satellite_environment("Media.DShow"));
        assert!(is_authority_satellite_header(Path::new(
            r"C:\sdk\um\xamlOM.h"
        )));
        assert!(is_authority_satellite_header(Path::new(r"C:\sdk\um\VFW.H")));
    }

    #[test]
    fn psapi_variants_define_the_version_before_first_include() {
        let v1 = psapi_source("#include <windows.h>\n", 1);
        let v2 = psapi_source("#include <windows.h>\n", 2);
        assert!(v1.contains("#define PSAPI_VERSION 1\n#include <psapi.h>"));
        assert!(v2.contains("#define PSAPI_VERSION 2\n#include <psapi.h>"));
    }
}
