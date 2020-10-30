// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from D3D12HelloWindow.h in https://github.com/Microsoft/DirectX-Graphics-Samples
// Original source is Copyright © Microsoft. All rights reserved. Licensed under the MIT License (MIT).

using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Microsoft.Windows.Win32;
using static Microsoft.Windows.Win32.D3D_FEATURE_LEVEL;
using static Microsoft.Windows.Win32.D3D_PRIMITIVE_TOPOLOGY;
using static Microsoft.Windows.Win32.D3D_ROOT_SIGNATURE_VERSION;
using static Microsoft.Windows.Win32.D3D12_COMMAND_LIST_TYPE;
using static Microsoft.Windows.Win32.D3D12_DESCRIPTOR_HEAP_TYPE;
using static Microsoft.Windows.Win32.D3D12_FENCE_FLAGS;
using static Microsoft.Windows.Win32.D3D12_HEAP_FLAGS;
using static Microsoft.Windows.Win32.D3D12_HEAP_TYPE;
using static Microsoft.Windows.Win32.D3D12_INPUT_CLASSIFICATION;
using static Microsoft.Windows.Win32.D3D12_PRIMITIVE_TOPOLOGY_TYPE;
using static Microsoft.Windows.Win32.D3D12_RESOURCE_STATES;
using static Microsoft.Windows.Win32.D3D12_ROOT_SIGNATURE_FLAGS;
using static Microsoft.Windows.Win32.DXGI_FORMAT;
using static Microsoft.Windows.Win32.DXGI_SWAP_EFFECT;
using static Microsoft.Windows.Win32.Apis;
using static SampleD3DApp.DXSampleHelper;
using System.Text;

namespace SampleD3DApp
{
    public unsafe class HelloTriangle12 : DX12Sample
    {
        private const uint FrameCount = 2;

        // Pipeline objects
        private D3D12_VIEWPORT _viewport;
        private RECT _scissorRect;
        private ComPtr<IDXGISwapChain3> _swapChain;
        private ComPtr<ID3D12Device> _device;
        private readonly ID3D12Resource*[] _renderTargets;
        private ComPtr<ID3D12CommandAllocator> _commandAllocator;
        private ComPtr<ID3D12CommandQueue> _commandQueue;
        private ComPtr<ID3D12RootSignature> _rootSignature;
        private ComPtr<ID3D12DescriptorHeap> _rtvHeap;
        private ComPtr<ID3D12PipelineState> _pipelineState;
        private ComPtr<ID3D12GraphicsCommandList> _commandList;
        private uint _rtvDescriptorSize;

        // App resources.
        private ComPtr<ID3D12Resource> _vertexBuffer;
        private D3D12_VERTEX_BUFFER_VIEW _vertexBufferView;

        // Synchronization objects.
        private uint _frameIndex;
        private FileSafeHandle _fenceEvent;
        private ComPtr<ID3D12Fence> _fence;
        private ulong _fenceValue;
        private DateTime _beginTime;

        public HelloTriangle12(uint width, uint height, string name)
            : base(width, height, name)
        {
            _renderTargets = new ID3D12Resource*[FrameCount];

            _viewport = new D3D12_VIEWPORT {
                TopLeftX = 0,
                TopLeftY = 0,
                Width = width,
                Height = height,
                MinDepth = D3D12_MIN_DEPTH,
                MaxDepth = D3D12_MAX_DEPTH
            };

            _scissorRect = new RECT {
                left = 0,
                top = 0,
                right = unchecked((int)width),
                bottom = unchecked((int)height)
            };
        }

        public override void OnInit()
        {
            LoadPipeline();
            LoadAssets();
            _beginTime = DateTime.Now;
        }

        // Update frame-based values.
        public override void OnUpdate()
        {
        }

        // Render the scene.
        public unsafe override void OnRender()
        {
            const float TwoPi = (float)(Math.PI * 2.0);
            const double SecondsPerRotation = 3.0;
            const double SecondsPerFullColorChange = 4.0;

            DateTime currentTime = DateTime.Now;
            TimeSpan elapsedTime = currentTime - this._beginTime;
            float currentRot = TwoPi * (float)(elapsedTime.TotalSeconds / SecondsPerRotation);

            var rotMatrix = Matrix4x4.CreateRotationZ(currentRot);
            var scaleMatrix = Matrix4x4.CreateScale(1, AspectRatio, 1);
            var worldMat = rotMatrix * scaleMatrix;

            // Record all the commands we need to render the scene into the command list.
            PopulateCommandList();

            // * 2.0 so we can go from 0.0 to 1.0 and back again
            float percentOfColorChange = (float)((elapsedTime.TotalSeconds % SecondsPerFullColorChange) / SecondsPerFullColorChange) * 2.0f;
            if (percentOfColorChange > 1.0f)
            {
                // Makes it go backwards from 1.0 to 0.0
                percentOfColorChange = 2.0f - percentOfColorChange;
            }

            var triangleVertices = stackalloc Vertex[TriangleVerticesCount] {
                new Vertex
                {
                    Position = Vector3.Transform(new Vector3(0.0f, 0.5f, 0.0f), worldMat),
                    // Red to green
                    Color = new Vector4(1.0f - percentOfColorChange, 0.0f + percentOfColorChange, 0.0f, 1.0f)
                },
                new Vertex
                {
                    Position = Vector3.Transform(new Vector3(0.5f, -0.5f, 0.0f), worldMat),
                    // Green to blue
                    Color = new Vector4(0.0f, 1.0f - percentOfColorChange, 0.0f + percentOfColorChange, 1.0f)
                },
                new Vertex
                {
                    Position = Vector3.Transform(new Vector3(-0.5f, -0.5f, 0.0f), worldMat),
                    // Blue to red
                    Color = new Vector4(0.0f + percentOfColorChange, 0.0f, 1.0f - percentOfColorChange, 1.0f)
                },
            };

            // Copy the triangle data to the vertex buffer.
            var readRange = new D3D12_RANGE();

            byte* pVertexDataBegin;
            ThrowIfFailed(nameof(ID3D12Resource.Map), _vertexBuffer.Get()->Map(Subresource: 0, &readRange, (void**)&pVertexDataBegin));
            Unsafe.CopyBlock(pVertexDataBegin, triangleVertices, VertexBufferSize);
            _vertexBuffer.Get()->Unmap(0, null);

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
                        {
                            ThrowIfFailed(nameof(IDXGISwapChain3.GetBuffer), _swapChain.Get()->GetBuffer(n, &iid, out renderTarget));
                            _device.Get()->CreateRenderTargetView(renderTarget, pDesc: null, rtvHandle);
                            rtvHandle.ptr = UIntPtr.Add(rtvHandle.ptr, (int)_rtvDescriptorSize);
                        }
                        _renderTargets[unchecked((int)n)] = renderTarget.Detach();
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
            }
        }

        // Define the geometry for a triangle.
        private const int TriangleVerticesCount = 3;
        private static readonly uint VertexBufferSize = (uint)sizeof(Vertex) * TriangleVerticesCount;

        // Load the sample assets.
        private void LoadAssets()
        {
            Guid iid;
            ID3DBlob* signature = null;
            ID3DBlob* error = null;
            ID3DBlob* vertexShader = null;
            ID3DBlob* pixelShader = null;

            try
            {
                // Create an empty root signature.
                {
                    var rootSignatureDesc = new D3D12_ROOT_SIGNATURE_DESC {
                        Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT
                    };

                    ThrowIfFailed(nameof(D3D12SerializeRootSignature), D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, out signature, &error));

                    iid = IID_ID3D12RootSignature;
                    ThrowIfFailed(nameof(ID3D12Device.CreateRootSignature), _device.Get()->CreateRootSignature(nodeMask: 0, signature->GetBufferPointer(), signature->GetBufferSize(), &iid, out _rootSignature));
                }

                // Create the pipeline state, which includes compiling and loading shaders.
                {
                    var compileFlags = 0u;

#if DEBUG
                    // Enable better shader debugging with the graphics debugging tools.
                    compileFlags |= D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#endif
                    //fixed (char* fileName = GetAssetFullPath(@"D3D12\Assets\Shaders\HelloTriangle.hlsl"))
                    string fileName = GetAssetFullPath(@"Assets\D3D12\Shaders\HelloTriangle.hlsl");
                    {
                        var entryPoint = "VSMain";    // VSMain
                        var target = "vs_5_0";        // vs_5_0
                        ThrowIfFailed(nameof(D3DCompileFromFile), D3DCompileFromFile(fileName, pDefines: null, pInclude: null, entryPoint, target, compileFlags, Flags2: 0, out vertexShader, ppErrorMsgs: null));

                        entryPoint = "PSMain";        // PSMain
                        target = "ps_5_0";            // ps_5_0
                        ThrowIfFailed(nameof(D3DCompileFromFile), D3DCompileFromFile(fileName, pDefines: null, pInclude: null, entryPoint, target, compileFlags, Flags2: 0, out pixelShader, ppErrorMsgs: null));
                    }

                    // Define the vertex input layout.
                    const int InputElementDescsCount = 2;

                    byte[] posChars = Encoding.ASCII.GetBytes("POSITION");
                    byte[] colorChars = Encoding.ASCII.GetBytes("COLOR");
                    fixed (byte* semanticName0 = posChars)
                    fixed (byte* semanticName1 = colorChars)
                    {
                        var inputElementDescs = stackalloc D3D12_INPUT_ELEMENT_DESC[InputElementDescsCount] {
                            new D3D12_INPUT_ELEMENT_DESC
                            {
                                SemanticName = (sbyte*)semanticName0,
                                Format = DXGI_FORMAT_R32G32B32_FLOAT,
                                InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,
                            },
                            new D3D12_INPUT_ELEMENT_DESC
                            {
                                SemanticName = (sbyte*)semanticName1,
                                Format = DXGI_FORMAT_R32G32B32A32_FLOAT,
                                AlignedByteOffset = 12,
                                InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,
                            },
                        };

                        // Describe and create the graphics pipeline state object (PSO).
                        var psoDesc = new D3D12_GRAPHICS_PIPELINE_STATE_DESC
                        {
                            InputLayout = new D3D12_INPUT_LAYOUT_DESC
                            {
                                pInputElementDescs = inputElementDescs,
                                NumElements = InputElementDescsCount,
                            },
                            pRootSignature = _rootSignature,
                            VS = new D3D12_SHADER_BYTECODE() { pShaderBytecode = vertexShader->GetBufferPointer(), BytecodeLength = vertexShader->GetBufferSize() },
                            PS = new D3D12_SHADER_BYTECODE() { pShaderBytecode = pixelShader->GetBufferPointer(), BytecodeLength = pixelShader->GetBufferSize() },
                            RasterizerState = D3D12_RASTERIZER_DESC.DEFAULT,
                            BlendState = D3D12_BLEND_DESC.DEFAULT,
                            DepthStencilState = D3D12_DEPTH_STENCIL_DESC.DEFAULT,
                            SampleMask = uint.MaxValue,
                            PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE,
                            NumRenderTargets = 1,
                            SampleDesc = new DXGI_SAMPLE_DESC() { Count = 1, Quality = 0 },
                        };
                        psoDesc.DepthStencilState.DepthEnable = FALSE;
                        psoDesc.RTVFormats.e0 = DXGI_FORMAT_R8G8B8A8_UNORM;

                        iid = IID_ID3D12PipelineState;
                        ThrowIfFailed(nameof(ID3D12Device.CreateGraphicsPipelineState), _device.Get()->CreateGraphicsPipelineState(&psoDesc, &iid, out _pipelineState));
                    }
                }

                // Create the command list.
                iid = IID_ID3D12GraphicsCommandList;
                ThrowIfFailed(nameof(ID3D12Device.CreateCommandList), _device.Get()->CreateCommandList(nodeMask: 0, D3D12_COMMAND_LIST_TYPE_DIRECT, _commandAllocator.Get(), _pipelineState.Get(), &iid, out _commandList));

                // Command lists are created in the recording state, but there is nothing
                // to record yet. The main loop expects it to be closed, so close it now.
                ThrowIfFailed(nameof(ID3D12GraphicsCommandList.Close), _commandList.Get()->Close());

                // Create the vertex buffer.
                {
                    // Note: using upload heaps to transfer static data like vert buffers is not
                    // recommended. Every time the GPU needs it, the upload heap will be marshalled
                    // over. Please read up on Default Heap usage. An upload heap is used here for
                    // code simplicity and because there are very few verts to actually transfer.
                    var heapProperties = new D3D12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
                    var bufferDesc = D3D12_RESOURCE_DESC.Buffer(VertexBufferSize);

                    iid = IID_ID3D12Resource;
                    ThrowIfFailed(nameof(ID3D12Device.CreateCommittedResource), _device.Get()->CreateCommittedResource(
                        &heapProperties,
                        D3D12_HEAP_FLAG_NONE,
                        &bufferDesc,
                        D3D12_RESOURCE_STATE_GENERIC_READ,
                        pOptimizedClearValue: null,
                        &iid,
                        out _vertexBuffer
                        ));

                    // Initialize the vertex buffer view.
                    _vertexBufferView.BufferLocation = _vertexBuffer.Get()->GetGPUVirtualAddress();
                    _vertexBufferView.StrideInBytes = (uint)sizeof(Vertex);
                    _vertexBufferView.SizeInBytes = VertexBufferSize;
                }

                // Create synchronization objects and wait until assets have been uploaded to the GPU.
                {
                    iid = IID_ID3D12Fence;
                    ThrowIfFailed(nameof(ID3D12Device.CreateFence), _device.Get()->CreateFence(0, D3D12_FENCE_FLAG_NONE, &iid, out _fence));
                    _fenceValue = 1;

                    // Create an event handle to use for frame synchronization.
                    _fenceEvent = CreateEventW(lpEventAttributes: null, bManualReset: FALSE, bInitialState: FALSE, lpName: null);
                    if (_fenceEvent == null)
                    {
                        var hr = Marshal.GetHRForLastWin32Error();
                        Marshal.ThrowExceptionForHR(hr);
                    }

                    // Wait for the command list to execute; we are reusing the same command
                    // list in our main loop but for now, we just want to wait for setup to
                    // complete before continuing.
                    WaitForPreviousFrame();
                }
            }
            finally
            {
                if (signature != null)
                {
                    signature->Release();
                }

                if (error != null)
                {
                    error->Release();
                }

                if (vertexShader != null)
                {
                    vertexShader->Release();
                }

                if (pixelShader != null)
                {
                    pixelShader->Release();
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
            ThrowIfFailed(nameof(ID3D12GraphicsCommandList.Reset), _commandList.Get()->Reset(_commandAllocator.Get(), _pipelineState.Get()));

            // Set necessary state.
            _commandList.Get()->SetGraphicsRootSignature(_rootSignature);

            D3D12_VIEWPORT[] viewports = new D3D12_VIEWPORT[] { _viewport };
            _commandList.Get()->RSSetViewports(1, viewports);

            RECT[] scissorRects = new RECT[] { _scissorRect };
            _commandList.Get()->RSSetScissorRects(1, scissorRects);

            // Indicate that the back buffer will be used as a render target.
            D3D12_RESOURCE_BARRIER[] barriers = new D3D12_RESOURCE_BARRIER[] { D3D12_RESOURCE_BARRIER.InitTransition(_renderTargets[unchecked((int)_frameIndex)], D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET) };
            _commandList.Get()->ResourceBarrier(1, barriers);

            var rtvHandle = _rtvHeap.Get()->GetCPUDescriptorHandleForHeapStart();
            rtvHandle.ptr = (UIntPtr)((byte*)rtvHandle.ptr + (_frameIndex * _rtvDescriptorSize));
            _commandList.Get()->OMSetRenderTargets(1, &rtvHandle, FALSE, null);

            // Record commands.
            var clearColor = stackalloc float[4] { 0.0f, 0.2f, 0.4f, 1.0f };
            _commandList.Get()->ClearRenderTargetView(rtvHandle, clearColor, NumRects: 0, null);
            _commandList.Get()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

            D3D12_VERTEX_BUFFER_VIEW[] vertexBufferViews = new D3D12_VERTEX_BUFFER_VIEW[] { _vertexBufferView };
            _commandList.Get()->IASetVertexBuffers(StartSlot: 0, 1, vertexBufferViews);

            _commandList.Get()->DrawInstanced(VertexCountPerInstance: 3, InstanceCount: 1, StartVertexLocation: 0, StartInstanceLocation: 0);

            // Indicate that the back buffer will now be used to present.
            barriers[0] = D3D12_RESOURCE_BARRIER.InitTransition(_renderTargets[unchecked((int)_frameIndex)], D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
            _commandList.Get()->ResourceBarrier(1, barriers);

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
            _rootSignature?.Dispose();
            _rtvHeap?.Dispose();
            _pipelineState?.Dispose();
            _commandList?.Dispose();
            _vertexBuffer?.Dispose();
            _fence?.Dispose();

            base.Dispose(isDisposing);
        }

        private struct Vertex
        {
            public Vector3 Position;

            public Vector4 Color;
        }
    }
}
