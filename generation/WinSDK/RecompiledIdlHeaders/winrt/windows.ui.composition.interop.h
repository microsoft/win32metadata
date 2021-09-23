
//---------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
//---------------------------------------------------------------------------

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <windows.ui.composition.h>
#include <sdkddkver.h>

#ifndef BUILD_WINDOWS
namespace ABI {
#endif

namespace Windows {
namespace UI {
namespace Composition {

typedef interface ICompositionDrawingSurfaceInterop ICompositionDrawingSurfaceInterop;
typedef interface ICompositionDrawingSurfaceInterop2 ICompositionDrawingSurfaceInterop2;
typedef interface ICompositorInterop ICompositorInterop;


#undef INTERFACE
#define INTERFACE ICompositionDrawingSurfaceInterop
DECLARE_INTERFACE_IID_(ICompositionDrawingSurfaceInterop, IUnknown, "FD04E6E3-FE0C-4C3C-AB19-A07601A576EE")
{
    IFACEMETHOD(BeginDraw)(
        _In_opt_ const RECT * updateRect,
        _In_ REFIID iid,
        _COM_Outptr_ void ** updateObject,
        _Out_ POINT * updateOffset
        ) PURE;

    IFACEMETHOD(EndDraw)(
        ) PURE;

    IFACEMETHOD(Resize)(
        _In_ SIZE sizePixels
        ) PURE;

    IFACEMETHOD(Scroll)(
        _In_opt_ const RECT * scrollRect,
        _In_opt_ const RECT * clipRect,
        _In_ int offsetX,
        _In_ int offsetY
        ) PURE;

    IFACEMETHOD(ResumeDraw)(
        ) PURE;

    IFACEMETHOD(SuspendDraw)(
        ) PURE;
};

#undef INTERFACE
#define INTERFACE ICompositionDrawingSurfaceInterop2
DECLARE_INTERFACE_IID_(ICompositionDrawingSurfaceInterop2, ICompositionDrawingSurfaceInterop, "41E64AAE-98C0-4239-8E95-A330DD6AA18B")
{
    IFACEMETHOD(CopySurface)(
        _In_ IUnknown* destinationResource,
        _In_ int destinationOffsetX,
        _In_ int destinationOffsetY,
        _In_opt_ const RECT * sourceRectangle
        ) PURE;
};

#undef INTERFACE
#define INTERFACE ICompositionGraphicsDeviceInterop
DECLARE_INTERFACE_IID_(ICompositionGraphicsDeviceInterop, IUnknown, "A116FF71-F8BF-4C8A-9C98-70779A32A9C8")
{
    IFACEMETHOD(GetRenderingDevice)(
        _COM_Outptr_ IUnknown ** value
        ) PURE;

    IFACEMETHOD(SetRenderingDevice)(
        _In_ IUnknown * value
        ) PURE;
};


#undef INTERFACE
#define INTERFACE ICompositorInterop
DECLARE_INTERFACE_IID_(ICompositorInterop, IUnknown, "25297D5C-3AD4-4C9C-B5CF-E36A38512330")
{
    IFACEMETHOD(CreateCompositionSurfaceForHandle)(
        _In_ HANDLE swapChain,
        _COM_Outptr_ ICompositionSurface ** result
        ) PURE;

    IFACEMETHOD(CreateCompositionSurfaceForSwapChain)(
        _In_ IUnknown * swapChain,
        _COM_Outptr_ ICompositionSurface ** result
        ) PURE;

    IFACEMETHOD(CreateGraphicsDevice)(
        _In_ IUnknown * renderingDevice,
        _COM_Outptr_ ICompositionGraphicsDevice ** result
        ) PURE;
};


#undef INTERFACE
#define INTERFACE ISwapChainInterop
DECLARE_INTERFACE_IID_(ISwapChainInterop, IUnknown, "26f496a0-7f38-45fb-88f7-faaabe67dd59")
{
    IFACEMETHOD(SetSwapChain)(
        _In_ IUnknown * swapChain) PURE;
};

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

namespace Interactions
{

#undef INTERFACE
#define INTERFACE IVisualInteractionSourceInterop
DECLARE_INTERFACE_IID_(IVisualInteractionSourceInterop, IUnknown, "11F62CD1-2F9D-42D3-B05F-D6790D9E9F8E")
{
    IFACEMETHOD(TryRedirectForManipulation)(
        _In_ const POINTER_INFO& pointerInfo
        ) PURE;
};

} // Interactions

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

namespace Desktop {

    typedef interface IDesktopWindowTarget IDesktopWindowTarget;


#undef INTERFACE
#define INTERFACE ICompositionCapabilitiesInteropFactory
DECLARE_INTERFACE_IID_(ICompositionCapabilitiesInteropFactory, IInspectable, "2C9DB356-E70D-4642-8298-BC4AA5B4865C")
{
    IFACEMETHOD(GetForWindow)(
        _In_ HWND hwnd,
        _COM_Outptr_ ICompositionCapabilities ** result
        ) PURE;
};

#undef INTERFACE
#define INTERFACE ICompositorDesktopInterop
DECLARE_INTERFACE_IID_(ICompositorDesktopInterop, IUnknown, "29E691FA-4567-4DCA-B319-D0F207EB6807")
{
    IFACEMETHOD(CreateDesktopWindowTarget)(
        _In_ HWND hwndTarget,
        _In_ BOOL isTopmost,
        _COM_Outptr_ IDesktopWindowTarget ** result
        ) PURE;

    IFACEMETHOD(EnsureOnThread)(
        _In_ DWORD threadId
        ) PURE;
};


#undef INTERFACE
#define INTERFACE IDesktopWindowTargetInterop
DECLARE_INTERFACE_IID_(IDesktopWindowTargetInterop, IUnknown, "35DBF59E-E3F9-45B0-81E7-FE75F4145DC9")
{
    IFACEMETHOD(get_Hwnd)(
        _Outptr_ HWND * value
        ) PURE;
};


#undef INTERFACE
#define INTERFACE IDesktopWindowContentBridgeInterop
DECLARE_INTERFACE_IID_(IDesktopWindowContentBridgeInterop, IUnknown, "37642806-F421-4FD0-9F82-23AE7C776182")
{
    IFACEMETHOD(Initialize)(
        _In_ Windows::UI::Composition::ICompositor* compositor, _In_ HWND parentHwnd) PURE;

    IFACEMETHOD(get_Hwnd)(
        _Outptr_ HWND * value
        ) PURE;

    IFACEMETHOD(get_AppliedScaleFactor)(
        _Out_ float* value
        ) PURE;
};

} // namespace Desktop
} // namespace Composition
} // namespace UI
} // namespace Windows
#ifndef BUILD_WINDOWS
} // namespace ABI 
#endif
