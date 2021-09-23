using System;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;
using Windows.Win32.System.PropertiesSystem; // For PROPERTYKEY
using Windows.Win32.System.SystemServices;
using static Windows.Win32.Foundation.Apis; // Various constants
using static Windows.Win32.System.Diagnostics.Debug.WIN32_ERROR;
using static Windows.Win32.System.SystemServices.Apis; // Various constants
using static Windows.Win32.Media.Multimedia.Apis; // Various constants
using static Windows.Win32.Media.Audio.CoreAudio.Apis; // Various constants
using static Windows.Win32.Graphics.DirectShow.Apis; // Various constants
using static Windows.Win32.UI.WindowsAndMessaging.Apis; // For WM_USER
using static Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS; // For FILE_* constants
using static Windows.Win32.System.Diagnostics.Debug.FACILITY_CODE; // For MAKE_HRESULT constants


namespace Windows.Win32.Networking.Clustering
{
    public static partial class Apis
    {
        public const uint CLUSTER_VERSION_FLAG_MIXED_MODE = 0x00000001;

        public const uint CLUSTER_VERSION_UNKNOWN = 0xFFFFFFFF;

        public const uint NT4_MAJOR_VERSION = 1;

        public const uint NT4SP4_MAJOR_VERSION = 2;

        public const uint NT5_MAJOR_VERSION = 3;

        public const uint NT51_MAJOR_VERSION = 4;

        public const uint NT6_MAJOR_VERSION = 5;

        public const uint NT7_MAJOR_VERSION = 6;

        public const uint NT8_MAJOR_VERSION = 7;

        public const uint NT9_MAJOR_VERSION = 8;

        public const uint NT10_MAJOR_VERSION = 9;

        public const uint NT11_MAJOR_VERSION = 10;

        public const uint NT12_MAJOR_VERSION = 11;

        public const uint WS2016_TP4_UPGRADE_VERSION = 6;

        public const uint WS2016_TP5_UPGRADE_VERSION = 7;

        public const uint WS2016_RTM_UPGRADE_VERSION = 8;

        public const uint RS3_UPGRADE_VERSION = 1;

        public const uint RS4_UPGRADE_VERSION = 2;

        public const uint RS5_UPGRADE_VERSION = 3;

        public const uint NINETEEN_H1_UPGRADE_VERSION = 1;

        public const uint NINETEEN_H2_UPGRADE_VERSION = 2;

        public const uint CLUSAPI_VERSION_SERVER2008 = 0x00000600;

        public const uint CLUSAPI_VERSION_SERVER2008R2 = 0x00000700;

        public const uint CLUSAPI_VERSION_WINDOWS8 = 0x00000701;

        public const uint CLUSAPI_VERSION_WINDOWSBLUE = 0x00000702;

        public const uint CLUSAPI_VERSION_WINTHRESHOLD = 0x00000703;

        public const uint CLUSAPI_VERSION_RS3 = 0x00000A00;

        public const uint CREATE_CLUSTER_MAJOR_VERSION_MASK = 0xFFFFFF00;

        public const uint CLUSTER_INSTALLED = 0x00000001;

        public const uint CLUSTER_CONFIGURED = 0x00000002;

        public const uint CLUSTER_RUNNING = 0x00000010;

        public const uint CLUS_HYBRID_QUORUM = 1024;

        public const uint CLUS_NODE_MAJORITY_QUORUM = 0;

        public const uint CLUSCTL_RESOURCE_STATE_CHANGE_REASON_VERSION_1 = 1;

        public const uint CLUSREG_DATABASE_SYNC_WRITE_TO_ALL_NODES = 1;

        public const uint CLUSREG_DATABASE_ISOLATE_READ = 2;

        public const uint CLUSTER_ENUM_ITEM_VERSION_1 = 0x00000001;

        public const uint CLUSTER_CREATE_GROUP_INFO_VERSION_1 = 0x00000001;

        public const uint GROUPSET_READY_SETTING_DELAY = 0x00000001;

        public const uint GROUPSET_READY_SETTING_ONLINE = 0x00000002;

        public const uint GROUPSET_READY_SETTING_OS_HEARTBEAT = 0x00000003;

        public const uint GROUPSET_READY_SETTING_APPLICATION_READY = 0x00000004;

        public const int CLUSAPI_READ_ACCESS = 0x00000001;

        public const int CLUSAPI_CHANGE_ACCESS = 0x00000002;

        public const int CLUSAPI_NO_ACCESS = 0x00000004;

        public const uint CLUSTER_SET_ACCESS_TYPE_ALLOWED = 0;

        public const uint CLUSTER_SET_ACCESS_TYPE_DENIED = 1;

        public const uint CLUSTER_DELETE_ACCESS_CONTROL_ENTRY = 2;

        public const ulong CLUSGROUPSET_STATUS_GROUPS_PENDING = 0x0000000000000001;

        public const ulong CLUSGROUPSET_STATUS_GROUPS_ONLINE = 0x0000000000000002;

        public const ulong CLUSGROUPSET_STATUS_OS_HEARTBEAT = 0x0000000000000004;

        public const ulong CLUSGROUPSET_STATUS_APPLICATION_READY = 0x0000000000000008;

        public const uint CLUSTER_AVAILABILITY_SET_CONFIG_V1 = 0x00000001;

        public const uint CLUSTER_GROUP_ENUM_ITEM_VERSION_1 = 0x00000001;

        public const uint CLUSTER_RESOURCE_ENUM_ITEM_VERSION_1 = 0x00000001;

        public const uint CLUSAPI_NODE_PAUSE_REMAIN_ON_PAUSED_NODE_ON_MOVE_ERROR = 0x00000001;

        public const uint CLUSAPI_NODE_AVOID_PLACEMENT = 0x00000002;

        public const uint CLUSAPI_NODE_PAUSE_RETRY_DRAIN_ON_FAILURE = 0x00000004;

        public const ulong CLUSGRP_STATUS_LOCKED_MODE = 0x0000000000000001;

        public const ulong CLUSGRP_STATUS_PREEMPTED = 0x0000000000000002;

        public const ulong CLUSGRP_STATUS_WAITING_IN_QUEUE_FOR_MOVE = 0x0000000000000004;

        public const ulong CLUSGRP_STATUS_PHYSICAL_RESOURCES_LACKING = 0x0000000000000008;

        public const ulong CLUSGRP_STATUS_WAITING_TO_START = 0x0000000000000010;

        public const ulong CLUSGRP_STATUS_EMBEDDED_FAILURE = 0x0000000000000020;

        public const ulong CLUSGRP_STATUS_OFFLINE_DUE_TO_ANTIAFFINITY_CONFLICT = 0x0000000000000040;

        public const ulong CLUSGRP_STATUS_NETWORK_FAILURE = 0x0000000000000080;

        public const ulong CLUSGRP_STATUS_UNMONITORED = 0x0000000000000100;

        public const ulong CLUSGRP_STATUS_OS_HEARTBEAT = 0x0000000000000200;

        public const ulong CLUSGRP_STATUS_APPLICATION_READY = 0x0000000000000400;

        public const ulong CLUSGRP_STATUS_OFFLINE_NOT_LOCAL_DISK_OWNER = 0x0000000000000800;

        public const ulong CLUSGRP_STATUS_WAITING_FOR_DEPENDENCIES = 0x0000000000001000;

        public const ulong CLUSRES_STATUS_LOCKED_MODE = 0x0000000000000001;

        public const ulong CLUSRES_STATUS_EMBEDDED_FAILURE = 0x0000000000000002;

        public const ulong CLUSRES_STATUS_FAILED_DUE_TO_INSUFFICIENT_CPU = 0x0000000000000004;

        public const ulong CLUSRES_STATUS_FAILED_DUE_TO_INSUFFICIENT_MEMORY = 0x0000000000000008;

        public const ulong CLUSRES_STATUS_FAILED_DUE_TO_INSUFFICIENT_GENERIC_RESOURCES = 0x0000000000000010;

        public const ulong CLUSRES_STATUS_NETWORK_FAILURE = 0x0000000000000020;

        public const ulong CLUSRES_STATUS_UNMONITORED = 0x0000000000000040;

        public const ulong CLUSRES_STATUS_OS_HEARTBEAT = 0x0000000000000080;

        public const ulong CLUSRES_STATUS_APPLICATION_READY = 0x0000000000000100;

        public const ulong CLUSRES_STATUS_OFFLINE_NOT_LOCAL_DISK_OWNER = 0x0000000000000200;

        public const uint CLUSAPI_GROUP_ONLINE_IGNORE_RESOURCE_STATUS = 0x00000001;

        public const uint CLUSAPI_GROUP_ONLINE_SYNCHRONOUS = 0x00000002;

        public const uint CLUSAPI_GROUP_ONLINE_BEST_POSSIBLE_NODE = 0x00000004;

        public const uint CLUSAPI_GROUP_OFFLINE_IGNORE_RESOURCE_STATUS = 0x00000001;

        public const uint CLUSAPI_RESOURCE_ONLINE_IGNORE_RESOURCE_STATUS = 0x00000001;

        public const uint CLUSAPI_RESOURCE_ONLINE_DO_NOT_UPDATE_PERSISTENT_STATE = 0x00000002;

        public const uint CLUSAPI_RESOURCE_ONLINE_NECESSARY_FOR_QUORUM = 0x00000004;

        public const uint CLUSAPI_RESOURCE_ONLINE_BEST_POSSIBLE_NODE = 0x00000008;

        public const uint CLUSAPI_RESOURCE_OFFLINE_IGNORE_RESOURCE_STATUS = 0x00000001;

        public const uint CLUSAPI_RESOURCE_OFFLINE_FORCE_WITH_TERMINATION = 0x00000002;

        public const uint CLUSAPI_RESOURCE_OFFLINE_DO_NOT_UPDATE_PERSISTENT_STATE = 0x00000004;

        public const uint CLUSAPI_RESOURCE_OFFLINE_REASON_NONE = 0x00000000;

        public const uint CLUSAPI_RESOURCE_OFFLINE_REASON_UNKNOWN = 0x00000001;

        public const uint CLUSAPI_RESOURCE_OFFLINE_REASON_MOVING = 0x00000002;

        public const uint CLUSAPI_RESOURCE_OFFLINE_REASON_USER_REQUESTED = 0x00000004;

        public const uint CLUSAPI_RESOURCE_OFFLINE_REASON_BEING_DELETED = 0x00000008;

        public const uint CLUSAPI_RESOURCE_OFFLINE_REASON_BEING_RESTARTED = 0x00000010;

        public const uint CLUSAPI_RESOURCE_OFFLINE_REASON_PREEMPTED = 0x00000020;

        public const uint CLUSAPI_RESOURCE_OFFLINE_REASON_SHUTTING_DOWN = 0x00000040;

        public const uint CLUSAPI_GROUP_MOVE_IGNORE_RESOURCE_STATUS = 0x00000001;

        public const uint CLUSAPI_GROUP_MOVE_RETURN_TO_SOURCE_NODE_ON_ERROR = 0x00000002;

        public const uint CLUSAPI_GROUP_MOVE_QUEUE_ENABLED = 0x00000004;

        public const uint CLUSAPI_GROUP_MOVE_HIGH_PRIORITY_START = 0x00000008;

        public const uint CLUSAPI_GROUP_MOVE_FAILBACK = 0x00000010;

        public const uint CLUSAPI_GROUP_MOVE_IGNORE_AFFINITY_RULE = 0x00000020;

        public const ulong CLUSAPI_CHANGE_RESOURCE_GROUP_FORCE_MOVE_TO_CSV = 0x0000000000000001;

        public const uint GROUP_FAILURE_INFO_VERSION_1 = 0x1;

        public const uint RESOURCE_FAILURE_INFO_VERSION_1 = 0x1;

        public const uint CLUS_ACCESS_ANY = 0;

        public const uint CLUS_ACCESS_READ = 0x01;

        public const uint CLUS_ACCESS_WRITE = 0x02;

        public const uint CLUS_NO_MODIFY = 0;

        public const uint CLUS_MODIFY = 0x01;

        public const uint CLUS_NOT_GLOBAL = 0;

        public const uint CLUS_GLOBAL = 0x01;

        public const uint CLUSCTL_ACCESS_SHIFT = 0;

        public const uint CLUSCTL_FUNCTION_SHIFT = 2;

        public const uint CLCTL_INTERNAL_SHIFT = 20;

        public const uint CLCTL_USER_SHIFT = 21;

        public const uint CLCTL_MODIFY_SHIFT = 22;

        public const uint CLCTL_GLOBAL_SHIFT = 23;

        public const uint CLUSCTL_OBJECT_SHIFT = 24;

        public const uint CLUSCTL_CONTROL_CODE_MASK = 0x3FFFFF;

        public const uint CLUSCTL_OBJECT_MASK = 0xFF;

        public const uint CLUSCTL_ACCESS_MODE_MASK = 0x03;

        public const uint CLCTL_CLUSTER_BASE = 0;

        public const int BitLockerEnabled = 0x00000001;

        public const int BitLockerDecrypted = 0x00000004;

        public const int BitlockerEncrypted = 0x00000008;

        public const int BitLockerDecrypting = 0x00000010;

        public const int BitlockerEncrypting = 0x00000020;

        public const int BitLockerPaused = 0x00000040;

        public const int BitLockerStopped = 0x00000080;

        public const ulong RedirectedIOReasonUserRequest = 0x0000000000000001;

        public const ulong RedirectedIOReasonUnsafeFileSystemFilter = 0x0000000000000002;

        public const ulong RedirectedIOReasonUnsafeVolumeFilter = 0x0000000000000004;

        public const ulong RedirectedIOReasonFileSystemTiering = 0x0000000000000008;

        public const ulong RedirectedIOReasonBitLockerInitializing = 0x0000000000000010;

        public const ulong RedirectedIOReasonReFs = 0x0000000000000020;

        public const ulong RedirectedIOReasonMax = 0x8000000000000000;

        public const ulong VolumeRedirectedIOReasonNoDiskConnectivity = 0x0000000000000001;

        public const ulong VolumeRedirectedIOReasonStorageSpaceNotAttached = 0x0000000000000002;

        public const ulong VolumeRedirectedIOReasonVolumeReplicationEnabled = 0x0000000000000004;

        public const ulong VolumeRedirectedIOReasonMax = 0x8000000000000000;

        public const uint MAX_OBJECTID = 64;

        public const uint MAX_CO_PASSWORD_LENGTH = 16;

        public const uint GUID_PRESENT = 0x1;

        public const uint CREATEDC_PRESENT = 0x2;

        public const uint MAX_CO_PASSWORD_LENGTHEX = 127;

        public const uint MAX_CO_PASSWORD_STORAGEEX = 128;

        public const uint MAX_CREATINGDC_LENGTH = 256;

        public const uint DNS_LENGTH = 64;

        public const uint MAINTENANCE_MODE_V2_SIG = 0xabbaf00f;

        public const uint NNLEN = 80;

        public const uint SR_REPLICATED_PARTITION_DISALLOW_MULTINODE_IO = 0x00000001;

        public const uint CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX2_FLAG_ADD_VOLUME_INFO = 0x00000001;

        public const uint CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX2_FLAG_FILTER_BY_POOL = 0x00000002;

        public const uint CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX2_FLAG_INCLUDE_NON_SHARED_DISKS = 0x00000004;

        public const uint CLRES_VERSION_V1_00 = 0x100;

        public const uint CLRES_VERSION_V2_00 = 0x200;

        public const uint CLRES_VERSION_V3_00 = 0x300;

        public const uint CLRES_VERSION_V4_00 = 0x400;

        public const uint CLUSCTL_GET_OPERATION_CONTEXT_PARAMS_VERSION_1 = 1;

        public const uint CLUSRESDLL_STATUS_OFFLINE_BUSY = 0x00000001;

        public const uint CLUSRESDLL_STATUS_OFFLINE_SOURCE_THROTTLED = 0x00000002;

        public const uint CLUSRESDLL_STATUS_OFFLINE_DESTINATION_THROTTLED = 0x00000004;

        public const uint CLUSRESDLL_STATUS_OFFLINE_DESTINATION_REJECTED = 0x00000008;

        public const uint CLUSRESDLL_STATUS_INSUFFICIENT_MEMORY = 0x00000010;

        public const uint CLUSRESDLL_STATUS_INSUFFICIENT_PROCESSOR = 0x00000020;

        public const uint CLUSRESDLL_STATUS_INSUFFICIENT_OTHER_RESOURCES = 0x00000040;

        public const uint CLUSRESDLL_STATUS_INVALID_PARAMETERS = 0x00000080;

        public const uint CLUSRESDLL_STATUS_NETWORK_NOT_AVAILABLE = 0x00000100;

        public const uint CLUS_RESDLL_OPEN_RECOVER_MONITOR_STATE = 0x00000001;

        public const uint CLUS_RESDLL_ONLINE_RECOVER_MONITOR_STATE = 0x00000001;

        public const uint CLUS_RESDLL_ONLINE_IGNORE_RESOURCE_STATUS = 0x00000002;

        public const uint CLUS_RESDLL_ONLINE_RETURN_TO_SOURCE_NODE_ON_ERROR = 0x00000004;

        public const uint CLUS_RESDLL_ONLINE_RESTORE_ONLINE_STATE = 0x00000008;

        public const uint CLUS_RESDLL_ONLINE_IGNORE_NETWORK_CONNECTIVITY = 0x00000010;

        public const uint CLUS_RESDLL_OFFLINE_IGNORE_RESOURCE_STATUS = 0x00000001;

        public const uint CLUS_RESDLL_OFFLINE_RETURN_TO_SOURCE_NODE_ON_ERROR = 0x00000002;

        public const uint CLUS_RESDLL_OFFLINE_QUEUE_ENABLED = 0x00000004;

        public const uint CLUS_RESDLL_OFFLINE_RETURNING_TO_SOURCE_NODE_BECAUSE_OF_ERROR = 0x00000008;

        public const uint CLUS_RESDLL_OFFLINE_DUE_TO_EMBEDDED_FAILURE = 0x00000010;

        public const uint CLUS_RESDLL_OFFLINE_IGNORE_NETWORK_CONNECTIVITY = 0x00000020;

        public const uint CLUS_RESDLL_OFFLINE_DO_NOT_UPDATE_PERSISTENT_STATE = 0x00000040;

        public const uint CLUS_RESDLL_OPEN_DONT_DELETE_TEMP_DISK = 0x00000002;

        public const uint RESTYPE_MONITOR_SHUTTING_DOWN_NODE_STOP = 0x00000001;

        public const uint RESTYPE_MONITOR_SHUTTING_DOWN_CLUSSVC_CRASH = 0x00000002;

        public const uint RESUTIL_PROPITEM_READ_ONLY = 0x00000001;

        public const uint RESUTIL_PROPITEM_REQUIRED = 0x00000002;

        public const uint RESUTIL_PROPITEM_SIGNED = 0x00000004;

        public const uint RESUTIL_PROPITEM_IN_MEMORY = 0x00000008;

        public const uint LOCKED_MODE_FLAGS_DONT_REMOVE_FROM_MOVE_QUEUE = 0x00000001;

        public const uint CLUSTER_HEALTH_FAULT_ARGS = 7;

        public const uint CLUSTER_HEALTH_FAULT_ID = 0;

        public const uint CLUSTER_HEALTH_FAULT_ERRORTYPE = 1;

        public const uint CLUSTER_HEALTH_FAULT_ERRORCODE = 2;

        public const uint CLUSTER_HEALTH_FAULT_DESCRIPTION = 3;

        public const uint CLUSTER_HEALTH_FAULT_PROVIDER = 4;

        public const uint CLUSTER_HEALTH_FAULT_FLAGS = 5;

        public const uint CLUSTER_HEALTH_FAULT_RESERVED = 6;

        public const uint CLUS_CREATE_CRYPT_CONTAINER_NOT_FOUND = 0x0001;

        public const uint SET_APPINSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR = 0x00000001;

    }
}
