using Windows.Win32.Interop;
namespace Windows.Win32.Networking.Clustering
{
    // Here becauase of: https://github.com/dotnet/ClangSharp/issues/367
    // Remove if this gets fixed
    [NativeTypeName("struct CLUSPROP_RESOURCE_CLASS_INFO : CLUSPROP_VALUE, CLUS_RESOURCE_CLASS_INFO")]
    [NativeInheritance("CLUS_RESOURCE_CLASS_INFO")]
    public partial struct CLUSPROP_RESOURCE_CLASS_INFO
    {
        public CLUSPROP_VALUE Base;

        public CLUS_RESOURCE_CLASS_INFO Base2;
    }

    // Here becauase of: https://github.com/dotnet/ClangSharp/issues/367
    // Remove if this gets fixed
    [NativeTypeName("struct _CLUSTER_SHARED_VOLUME_RENAME_INPUT : CLUSTER_SHARED_VOLUME_RENAME_INPUT_VOLUME, CLUSTER_SHARED_VOLUME_RENAME_INPUT_NAME")]
    [NativeInheritance("CLUSTER_SHARED_VOLUME_RENAME_INPUT_NAME")]
    public partial struct CLUSTER_SHARED_VOLUME_RENAME_INPUT
    {
        public CLUSTER_SHARED_VOLUME_RENAME_INPUT_VOLUME Base;

        public CLUSTER_SHARED_VOLUME_RENAME_INPUT_NAME Base2;
    }

    // Here becauase of: https://github.com/dotnet/ClangSharp/issues/367
    // Remove if this gets fixed
    [NativeTypeName("struct _CLUSTER_SHARED_VOLUME_RENAME_GUID_INPUT : CLUSTER_SHARED_VOLUME_RENAME_INPUT_VOLUME, CLUSTER_SHARED_VOLUME_RENAME_INPUT_GUID_NAME")]
    [NativeInheritance("CLUSTER_SHARED_VOLUME_RENAME_INPUT_GUID_NAME")]
    public partial struct CLUSTER_SHARED_VOLUME_RENAME_GUID_INPUT
    {
        public CLUSTER_SHARED_VOLUME_RENAME_INPUT_VOLUME Base;

        public CLUSTER_SHARED_VOLUME_RENAME_INPUT_GUID_NAME Base2;
    }

    // Here becauase of: https://github.com/dotnet/ClangSharp/issues/367
    // Remove if this gets fixed
    [NativeTypeName("struct CLUSPROP_PARTITION_INFO : CLUSPROP_VALUE, CLUS_PARTITION_INFO")]
    [NativeInheritance("CLUS_PARTITION_INFO")]
    public partial struct CLUSPROP_PARTITION_INFO
    {
        public CLUSPROP_VALUE Base;

        public CLUS_PARTITION_INFO Base2;
    }

    // Here becauase of: https://github.com/dotnet/ClangSharp/issues/367
    // Remove if this gets fixed
    [NativeTypeName("struct CLUSPROP_PARTITION_INFO_EX : CLUSPROP_VALUE, CLUS_PARTITION_INFO_EX")]
    [NativeInheritance("CLUS_PARTITION_INFO_EX")]
    public partial struct CLUSPROP_PARTITION_INFO_EX
    {
        public CLUSPROP_VALUE Base;

        public CLUS_PARTITION_INFO_EX Base2;
    }

    // Here becauase of: https://github.com/dotnet/ClangSharp/issues/367
    // Remove if this gets fixed
    [NativeTypeName("struct CLUSPROP_PARTITION_INFO_EX2 : CLUSPROP_PARTITION_INFO_EX, CLUS_PARTITION_INFO_EX2")]
    [NativeInheritance("CLUS_PARTITION_INFO_EX2")]
    public partial struct CLUSPROP_PARTITION_INFO_EX2
    {
        public CLUSPROP_PARTITION_INFO_EX Base;

        public CLUS_PARTITION_INFO_EX2 Base2;
    }

    // Here becauase of: https://github.com/dotnet/ClangSharp/issues/367
    // Remove if this gets fixed
    [NativeTypeName("struct CLUSPROP_FTSET_INFO : CLUSPROP_VALUE, CLUS_FTSET_INFO")]
    [NativeInheritance("CLUS_FTSET_INFO")]
    public partial struct CLUSPROP_FTSET_INFO
    {
        public CLUSPROP_VALUE Base;

        public CLUS_FTSET_INFO Base2;
    }

    // Here becauase of: https://github.com/dotnet/ClangSharp/issues/367
    // Remove if this gets fixed
    [NativeTypeName("struct CLUSPROP_SCSI_ADDRESS : CLUSPROP_VALUE, CLUS_SCSI_ADDRESS")]
    [NativeInheritance("CLUS_SCSI_ADDRESS")]
    public partial struct CLUSPROP_SCSI_ADDRESS
    {
        public CLUSPROP_VALUE Base;

        public CLUS_SCSI_ADDRESS Base2;
    }
}
