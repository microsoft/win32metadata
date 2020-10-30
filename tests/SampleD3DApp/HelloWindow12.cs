// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from D3D12HelloWindow.h in https://github.com/Microsoft/DirectX-Graphics-Samples
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Win32;
using static Microsoft.Windows.Win32.Apis;

using static Microsoft.Windows.Win32.D3D_FEATURE_LEVEL;
using static Microsoft.Windows.Win32.D3D12_COMMAND_LIST_TYPE;
using static Microsoft.Windows.Win32.D3D12_DESCRIPTOR_HEAP_TYPE;
using static Microsoft.Windows.Win32.D3D12_FENCE_FLAGS;
using static Microsoft.Windows.Win32.D3D12_RESOURCE_STATES;
using static Microsoft.Windows.Win32.DXGI_FORMAT;
using static Microsoft.Windows.Win32.DXGI_SWAP_EFFECT;

namespace SampleD3DApp
{
    public unsafe class HelloWindow12 : DX12Sample
    {
        private const uint FrameCount = 2;

        // Pipeline objects
        private ComPtr<IDXGISwapChain3> _swapChain;
        private ComPtr<ID3D12Device> _device;
        private readonly ID3D12Resource*[] _renderTargets;
        private ComPtr<ID3D12CommandAllocator> _commandAllocator;
        private ComPtr<ID3D12CommandQueue> _commandQueue;
        private ComPtr<ID3D12DescriptorHeap> _rtvHeap;
        private ComPtr<ID3D12GraphicsCommandList> _commandList;
        private uint _rtvDescriptorSize;

        // Synchronization objects.
        private uint _frameIndex;
        private FileSafeHandle _fenceEvent;
        private ComPtr<ID3D12Fence> _fence;
        private ulong _fenceValue;

        public HelloWindow12(uint width, uint height, string name)
            : base(width, height, name)
        {
            _renderTargets = new ID3D12Resource*[FrameCount];
        }

        public override void OnInit()
        {
            LoadPipeline();
            LoadAssets();
        }

        // Update frame-based values.
        public override void OnUpdate()
        {
        }

        // Render the scene.
        public override void OnRender()
        {
            // Record all the commands we need to render the scene into the command list.
            PopulateCommandList();

            // Execute the command list.
            const int CommandListsCount = 1;
            var ppCommandLists = stackalloc ID3D12CommandList*[CommandListsCount] {
                (ID3D12CommandList*)_commandList.Get(),
            };
            _commandQueue.Get()->ExecuteCommandLists(CommandListsCount, ppCommandLists);

            // Present the frame.
            ThrowIfFailed(nameof(IDXGISwapChain3.Present), _swapChain.Get()->Present(SyncInterval: 1, Flags: 0));

            WaitForPreviousFrame();
        }

        public override void OnDestroy()
        {
            // Ensure that the GPU is no longer referencing resources that are about to be
            // cleaned up by the destructor.
            WaitForPreviousFrame();
        }

        // Load the rendering pipeline dependencies.
        private void LoadPipeline()
        {
            Guid iid;
            ComPtr<ID3D12Debug> debugController = null;
            ComPtr<IDXGIFactory4> factory = null;
            ComPtr<IUnknown> adapter = null;
            ComPtr<IDXGISwapChain1> swapChain = null;

            try
            {
                var dxgiFactoryFlags = 0u;

#if DEBUG
                // Enable the debug layer (requires the Graphics Tools "optional feature").
                // NOTE: Enabling the debug layer after device creation will invalidate the active device.
                {
                    iid = IID_ID3D12Debug;
                    if (SUCCEEDED(D3D12GetDebugInterface(&iid, out debugController)))
                    {
                        debugController.Get()->EnableDebugLayer();

                        // Enable additional debug layers.
                        dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
                    }
                }
#endif

                iid = IID_IDXGIFactory4;
                ThrowIfFailed(nameof(CreateDXGIFactory2), CreateDXGIFactory2(dxgiFactoryFlags, &iid, out factory));

                if (UseWarpDevice)
                {
                    iid = IID_IDXGIAdapter;

                    ThrowIfFailed(nameof(IDXGIFactory4.EnumWarpAdapter), factory.Get()->EnumWarpAdapter(&iid, out adapter));
                }
                else
                {
                    adapter = GetHardwareAdapter((IDXGIFactory1*)factory.Get());
                }

                iid = IID_ID3D12Device;
                ThrowIfFailed(nameof(D3D12CreateDevice), D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, &iid, out _device));

                // Describe and create the command queue.
                var queueDesc = new D3D12_COMMAND_QUEUE_DESC();

                iid = IID_ID3D12CommandQueue;
                ThrowIfFailed(nameof(ID3D12Device.CreateCommandQueue), _device.Get()->CreateCommandQueue(&queueDesc, &iid, out _commandQueue));

                // Describe and create the swap chain.
                var swapChainDesc = new DXGI_SWAP_CHAIN_DESC1 {
                    BufferCount = FrameCount,
                    Width = Width,
                    Height = Height,
                    Format = DXGI_FORMAT_R8G8B8A8_UNORM,
                    BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT,
                    SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD,
                    SampleDesc = new DXGI_SAMPLE_DESC() { Count = 1, Quality = 0 },
                };

                ThrowIfFailed(nameof(IDXGIFactory4.CreateSwapChainForHwnd), factory.Get()->CreateSwapChainForHwnd(
                    (IUnknown*)_commandQueue.Get(),         // Swap chain needs the queue so that it can force a flush on it.
                    Win32Application.Hwnd,
                    &swapChainDesc,
                    pFullscreenDesc: null,
                    pRestrictToOutput: null,
                    out swapChain
                ));

                // This sample does not support fullscreen transitions.
                ThrowIfFailed(nameof(IDXGIFactory4.MakeWindowAssociation), factory.Get()->MakeWindowAssociation(Win32Application.Hwnd, DXGI_MWA_NO_ALT_ENTER));

                iid = IID_IDXGISwapChain3;
                ThrowIfFailed(nameof(IDXGISwapChain1.QueryInterface), swapChain.Get()->QueryInterface(&iid, out _swapChain));
                _frameIndex = _swapChain.Get()->GetCurrentBackBufferIndex();

                // Create descriptor heaps.
                {
                    // Describe and create a render target view (RTV) descriptor heap.
                    var rtvHeapDesc = new D3D12_DESCRIPTOR_HEAP_DESC {
                        NumDescriptors = FrameCount,
                        Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV,
                    };

                    iid = IID_ID3D12DescriptorHeap;
                    ThrowIfFailed(nameof(ID3D12Device.CreateDescriptorHeap), _device.Get()->CreateDescriptorHeap(&rtvHeapDesc, &iid, out _rtvHeap));

                    _rtvDescriptorSize = _device.Get()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
                }

                // Create frame resources.
                {
                    var rtvHandle = _rtvHeap.Get()->GetCPUDescriptorHandleForHeapStart();

                    // Create a RTV for each frame.
                    iid = IID_ID3D12Resource;

                    for (var n = 0u; n < FrameCount; n++)
                    {
                        ComPtr<ID3D12Resource> renderTarget;
                        ThrowIfFailed(nameof(IDXGISwapChain3.GetBuffer), _swapChain.Get()->GetBuffer(n, &iid, out renderTarget));
                        _device.Get()->CreateRenderTargetView(renderTarget.Get(), pDesc: null, rtvHandle);
                        rtvHandle.ptr = UIntPtr.Add(rtvHandle.ptr, (int)_rtvDescriptorSize);
                        //rtvHandle.Offset(1, _rtvDescriptorSize);

                        _renderTargets[unchecked((int)n)] = renderTarget;
                    }
                }

                iid = IID_ID3D12CommandAllocator;
                ThrowIfFailed(nameof(ID3D12Device.CreateRenderTargetView), _device.Get()->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, &iid, out _commandAllocator));
            }
            finally
            {
                debugController?.Dispose();
                factory?.Dispose();
                adapter?.Dispose();
                swapChain?.Dispose();
            }
        }

        // Load the sample assets.
        private void LoadAssets()
        {
            // Create the command list.
            var iid = IID_ID3D12GraphicsCommandList;
            ThrowIfFailed(nameof(ID3D12Device.CreateCommandList), _device.Get()->CreateCommandList(nodeMask: 0, D3D12_COMMAND_LIST_TYPE_DIRECT, _commandAllocator.Get(), pInitialState: null, &iid, out _commandList));

            // Command lists are created in the recording state, but there is nothing
            // to record yet. The main loop expects it to be closed, so close it now.
            ThrowIfFailed(nameof(ID3D12GraphicsCommandList.Close), _commandList.Get()->Close());

            // Create synchronization objects.
            {
                iid = IID_ID3D12Fence;
                ThrowIfFailed(nameof(ID3D12Device.CreateFence), _device.Get()->CreateFence(InitialValue: 0, D3D12_FENCE_FLAG_NONE, &iid, out _fence));
                _fenceValue = 1;

                // Create an event handle to use for frame synchronization.
                _fenceEvent = CreateEventW(lpEventAttributes: null, bManualReset: FALSE, bInitialState: FALSE, lpName: null);
                if (_fenceEvent == null)
                {
                    var hr = Marshal.GetHRForLastWin32Error();
                    Marshal.ThrowExceptionForHR(hr);
                }
            }
        }

        private void PopulateCommandList()
        {
            // Command list allocators can only be reset when the associated
            // command lists have finished execution on the GPU; apps should use
            // fences to determine GPU execution progress.
            ThrowIfFailed(nameof(ID3D12CommandAllocator.Reset), _commandAllocator.Get()->Reset());

            // However, when ExecuteCommandList() is called on a particular command
            // list, that command list can then be reset at any time and must be before
            // re-recording.
            ThrowIfFailed(nameof(ID3D12GraphicsCommandList.Reset), _commandList.Get()->Reset(_commandAllocator.Get(), null));

            // Indicate that the back buffer will be used as a render target.
            D3D12_RESOURCE_BARRIER[] barrier = new D3D12_RESOURCE_BARRIER[] { D3D12_RESOURCE_BARRIER.InitTransition(_renderTargets[unchecked((int)_frameIndex)], D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET) };
            _commandList.Get()->ResourceBarrier(1, barrier);

            var rtvHandle = _rtvHeap.Get()->GetCPUDescriptorHandleForHeapStart();
            rtvHandle.ptr = (UIntPtr)((byte*)rtvHandle.ptr + (_frameIndex * _rtvDescriptorSize));

            // Record commands.
            var clearColor = stackalloc float[4];
            {
                clearColor[0] = 0.0f;
                clearColor[1] = 0.2f;
                clearColor[2] = 0.4f;
                clearColor[3] = 1.0f;
            }
            _commandList.Get()->ClearRenderTargetView(rtvHandle, clearColor, 0, null);

            // Indicate that the back buffer will now be used to present.
            barrier[0] = D3D12_RESOURCE_BARRIER.InitTransition(_renderTargets[unchecked((int)_frameIndex)], D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
            _commandList.Get()->ResourceBarrier(1, barrier);

            ThrowIfFailed(nameof(ID3D12GraphicsCommandList.Close), _commandList.Get()->Close());
        }

        private void WaitForPreviousFrame()
        {
            // WAITING FOR THE FRAME TO COMPLETE BEFORE CONTINUING IS NOT BEST PRACTICE.
            // This is code implemented as such for simplicity. The D3D12HelloFrameBuffering
            // sample illustrates how to use fences for efficient resource usage and to
            // maximize GPU utilization.

            // Signal and increment the fence value.
            var fence = _fenceValue;
            ThrowIfFailed(nameof(ID3D12CommandQueue.Signal), _commandQueue.Get()->Signal(_fence.Get(), fence));
            _fenceValue++;

            // Wait until the previous frame is finished.
            if (_fence.Get()->GetCompletedValue() < fence)
            {
                ThrowIfFailed(nameof(ID3D12Fence.SetEventOnCompletion), _fence.Get()->SetEventOnCompletion(fence, _fenceEvent.DangerousGetHandle()));
                _ = WaitForSingleObject(_fenceEvent.DangerousGetHandle(), INFINITE);
            }

            _frameIndex = _swapChain.Get()->GetCurrentBackBufferIndex();
        }

        protected override void Dispose(bool isDisposing)
        {
            _swapChain?.Dispose();
            _device?.Dispose();

            for (var index = 0; index < FrameCount; index++)
            {
                var renderTarget = _renderTargets[index];
                if (renderTarget != null)
                {
                    _ = renderTarget->Release();
                    _renderTargets[index] = null;
                }
            }

            _commandAllocator?.Dispose();
            _commandQueue?.Dispose();
            _rtvHeap?.Dispose();
            _commandList?.Dispose();
            _fence?.Dispose();

            base.Dispose(isDisposing);
        }
    }
}
