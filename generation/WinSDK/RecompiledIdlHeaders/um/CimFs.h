/*
Copyright (c) Microsoft Corporation

   API to construct and mount Composite Images (CIMs)
*/

#include <windows.h>

#ifdef __cplusplus
extern "C"
{
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

DECLARE_HANDLE(CIMFS_IMAGE_HANDLE);

DECLARE_HANDLE(CIMFS_STREAM_HANDLE);

typedef enum CIM_MOUNT_IMAGE_FLAGS
{
    CIM_MOUNT_IMAGE_NONE    = 0x00000000,
    CIM_MOUNT_CHILD_ONLY    = 0x00000001,
    CIM_MOUNT_ENABLE_DAX    = 0x00000002,
    CIM_MOUNT_CACHE_FILES   = 0x00000004,
    CIM_MOUNT_CACHE_REGIONS = 0x00000008,
} CIM_MOUNT_IMAGE_FLAGS;

#ifdef DEFINE_ENUM_FLAG_OPERATORS
DEFINE_ENUM_FLAG_OPERATORS(CIM_MOUNT_IMAGE_FLAGS);
#endif

typedef struct _CIMFS_FILE_METADATA
{
    UINT32 Attributes;
    INT64 FileSize;

    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER LastAccessTime;

    _Field_size_bytes_(SecurityDescriptorSize) const void* SecurityDescriptorBuffer;
    UINT32 SecurityDescriptorSize;

    _Field_size_bytes_(ReparseDataSize) const void* ReparseDataBuffer;
    UINT32 ReparseDataSize;

    _Field_size_bytes_(EaBufferSize) const void* EaBuffer;
    UINT32 EaBufferSize;

} CIMFS_FILE_METADATA;

//
//  Creates a handle representing a new image at the location
//  specified, optionally based on an existing image at that
//  location.
//

STDAPI
CimCreateImage(_In_ PCWSTR imageContainingPath,
               _In_opt_ PCWSTR existingImageName,
               _In_opt_ PCWSTR newImageName,
               _Out_ CIMFS_IMAGE_HANDLE* cimImageHandle);

//
//  Adds a file with the specified metadata at a path relative
//  to the image represented by the image handle.
//  Returns a stream handle to the file primary data stream
//  which can be used to write data to the stream.
//

STDAPI
CimCreateFile(_In_ CIMFS_IMAGE_HANDLE cimImageHandle,
              _In_ PCWSTR imageRelativePath,
              _In_ const CIMFS_FILE_METADATA* fileMetadata,
              _Out_ CIMFS_STREAM_HANDLE* cimStreamHandle);

//
//  Adds the specified filesystem to the image represented by
//  the image handle.
//

STDAPI
CimAddFsToMergedImage(_In_ CIMFS_IMAGE_HANDLE cimImageHandle,
                      _In_ PCWSTR existingImageName);

//
//  Adds a file with the metadata and data pointing to the
//  specified backing file from the specified backing file
//  system at a path relative to the image represented by
//  the image handle.
//

STDAPI
CimCreateMergedFile(_In_ CIMFS_IMAGE_HANDLE cimImageHandle,
                    _In_ PCWSTR imageRelativePath,
                    _In_ PVOID backingFsPointer,
                    _In_ PVOID backingFilePointer,
                    _In_ UINT16 fsIndex);

//
//  Returns whether the file name specified exists in the
//  file system represented by the image handle.
//

STDAPI
CimLookupFile(_In_ CIMFS_IMAGE_HANDLE cimImageHandle,
              _In_ PCWSTR imageRelativePath,
              _Out_ PBOOLEAN exists);

//
//  Adds an alternate stream with the specified size at a path
//  relative to the image represented by the image handle.
//  Returns a handle to the stream which can be used to write
//  data to the stream.
//

STDAPI
CimCreateAlternateStream(_In_ CIMFS_IMAGE_HANDLE cimImageHandle,
                         _In_ PCWSTR imageRelativePath,
                         _In_ UINT64 streamSize,
                         _Out_ CIMFS_STREAM_HANDLE* cimStreamHandle);

//
//  Adds a hardlink to an existing path relative to the image
//  represented by the image handle.
//

STDAPI
CimCreateHardLink(_In_ CIMFS_IMAGE_HANDLE cimImageHandle,
                  _In_ PCWSTR imageRelativePath,
                  _In_ PCWSTR existingImageRelativePath);

//
//  Writes data from the specified buffer to the stream represented
//  by the stream handle.
//

STDAPI
CimWriteStream(_In_ CIMFS_STREAM_HANDLE cimStreamHandle,
               _In_reads_bytes_(bufferSize) const void* buffer,
               _In_ UINT32 bufferSize);

//
//  Frees resources associated with the stream handle.
//

STDAPI_(void)
CimCloseStream(_In_ CIMFS_STREAM_HANDLE cimStreamHandle);

//
//  Removes the file, stream, directory or hardlink at a path
//  relative to the image represented by the image handle.
//

STDAPI
CimDeletePath(_In_ CIMFS_IMAGE_HANDLE cimImageHandle,
              _In_ PCWSTR imageRelativePath);

//
//  Commits the image represented by the image handle. The handle
//  becomes invalid for further operations on the image.
//

STDAPI
CimCommitImage(_In_ CIMFS_IMAGE_HANDLE cimImageHandle);

//
//  Frees resources associated with the image handle.
//

STDAPI_(void)
CimCloseImage(_In_ CIMFS_IMAGE_HANDLE cimImageHandle);

//
//  Mounts the named image from the location specified by cimPath
//  as a volume with the volume GUID specified by volumeId.
//

STDAPI
CimMountImage(_In_ PCWSTR imageContainingPath,
              _In_ PCWSTR imageName,
              _In_ CIM_MOUNT_IMAGE_FLAGS mountImageFlags,
              _In_ const GUID* volumeId);

//
//  Mounts the merged image specified by the backingImagePaths
//  as a volume with the volume GUID specified by volumeId.
//

STDAPI
CimMergeMountImage(_In_ UINT32 numCimPaths,
                   _In_ PVOID backingImagePaths,
                   _In_ CIM_MOUNT_IMAGE_FLAGS mountImageFlags,
                   _In_ const GUID* volumeId);

//
//  Dismounts an image mounted with volumeId as the volume GUID.
//

STDAPI
CimDismountImage(_In_ const GUID* volumeId);

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif
