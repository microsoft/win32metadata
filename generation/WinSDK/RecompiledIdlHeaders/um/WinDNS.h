/*++

Copyright (c) 1996-2005  Microsoft Corporation

Module Name:

    windns.h

Abstract:

    Domain Name System (DNS)

    DNS definitions and DNS API.

Author:

    Jim Gilroy (jamesg)     December 7, 1996

Revision History:

--*/


#ifndef _WINDNS_INCLUDED_
#define _WINDNS_INCLUDED_
#include <winapifamily.h>

#pragma region Desktop Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)



#ifdef __cplusplus
extern "C"
{
#endif  // __cplusplus

//
//  Define QWORD -- not yet defined globally
//

typedef unsigned __int64 QWORD, *PQWORD;

//
//  DNS public types
//

typedef _Return_type_success_(return == 0) LONG    DNS_STATUS;
typedef DNS_STATUS                                *PDNS_STATUS;

//
//  IP Address
//

typedef DWORD   IP4_ADDRESS, *PIP4_ADDRESS;

#define SIZEOF_IP4_ADDRESS                  (4)
#define IP4_ADDRESS_STRING_LENGTH           (16)

//  Backcompat only -- length def contains terminating NULL

#define IP4_ADDRESS_STRING_BUFFER_LENGTH    (16)

//
//  IP Address Array type
//

typedef struct  _IP4_ARRAY
{
    DWORD           AddrCount;
#ifdef MIDL_PASS
    [size_is( AddrCount )]  IP4_ADDRESS  AddrArray[];
#else
    IP4_ADDRESS     AddrArray[1];
#endif
}
IP4_ARRAY, *PIP4_ARRAY;

//
//  IPv6 Address
//

#ifdef MIDL_PASS

#ifdef _WIN64
#pragma pack(push, 8)
#else
#pragma pack(push, 4)
#endif

typedef struct
{
    QWORD       IP6Qword[2];
}
IP6_ADDRESS, *PIP6_ADDRESS;

#pragma pack(pop)

#else // MIDL_PASS

typedef union
{
#ifdef _WIN64
    QWORD       IP6Qword[2];
#endif
    DWORD       IP6Dword[4];
    WORD        IP6Word[8];
    BYTE        IP6Byte[16];
#ifdef  IN6_ADDR
    IN6_ADDR    In6;
#endif
}
IP6_ADDRESS, *PIP6_ADDRESS;

#endif // MIDL_PASS

//
//  DNS Address structures representing both IPv4 and IPv6 addresses.
//

#define DNS_ADDR_MAX_SOCKADDR_LENGTH         (32)
#pragma pack(push, 1)

#if defined( MIDL_PASS )

typedef struct _DnsAddr
{
    CHAR        MaxSa[ DNS_ADDR_MAX_SOCKADDR_LENGTH ];
    DWORD       DnsAddrUserDword[ 8 ];
}
DNS_ADDR, *PDNS_ADDR;

typedef struct _DnsAddrArray
{
    DWORD           MaxCount;
    DWORD           AddrCount;
    DWORD           Tag;
    WORD            Family;
    WORD            WordReserved;
    DWORD           Flags;
    DWORD           MatchFlag;
    DWORD           Reserved1;
    DWORD           Reserved2;
    [size_is( AddrCount )]  DNS_ADDR    AddrArray[];
}
DNS_ADDR_ARRAY, *PDNS_ADDR_ARRAY;

#elif !defined( USE_PRIVATE_DNS_ADDR )

typedef struct _DnsAddr
{
    CHAR            MaxSa[ DNS_ADDR_MAX_SOCKADDR_LENGTH ];
    union
    {
        DWORD       DnsAddrUserDword[ 8 ];
    }
    Data;
}
DNS_ADDR, *PDNS_ADDR;

typedef struct _DnsAddrArray
{
    DWORD           MaxCount;
    DWORD           AddrCount;
    DWORD           Tag;
    WORD            Family;
    WORD            WordReserved;
    DWORD           Flags;
    DWORD           MatchFlag;
    DWORD           Reserved1;
    DWORD           Reserved2;
    DNS_ADDR        AddrArray[ 1 ];
}
DNS_ADDR_ARRAY, *PDNS_ADDR_ARRAY;

#endif  // MIDL_PASS
#pragma pack(pop)


//
//  IP6 string max is 45 bytes
//      - 6 WORDs in colon+hex (5 chars)
//      - last DWORD as IP4 (15 chars)
//  but include
//      - 11 bytes for scope ID
//      - 6 bytes for port (inc. colon)
//      - two bytes to bracket address with port
//      - terminating NULL
//
//  Note:  this is a change to previous def, but a single
//      definition continaing space for ALL possible IPv6
//      address strings, we elminate many possible errors

#undef  IP6_ADDRESS_STRING_LENGTH
#define IP6_ADDRESS_STRING_LENGTH           (65)
#define IP6_ADDRESS_STRING_BUFFER_LENGTH    (65)

//
//  IP4/IP6 combined maximum
//

#define DNS_ADDRESS_STRING_LENGTH           (IP6_ADDRESS_STRING_LENGTH)


//
//  Inline byte flipping -- can be done in registers
//

#define INLINE_WORD_FLIP(out, in)   \
        {                           \
            WORD _in = (in);        \
            (out) = (_in << 8) | (_in >> 8);  \
        }
#define INLINE_HTONS(out, in)   INLINE_WORD_FLIP(out, in)
#define INLINE_NTOHS(out, in)   INLINE_WORD_FLIP(out, in)

#define INLINE_DWORD_FLIP(out, in)  \
        {                           \
            DWORD _in = (in);       \
            (out) = ((_in << 8) & 0x00ff0000) | \
                    (_in << 24)               | \
                    ((_in >> 8) & 0x0000ff00) | \
                    (_in >> 24);                \
        }
#define INLINE_NTOHL(out, in) INLINE_DWORD_FLIP(out, in)
#define INLINE_HTONL(out, in) INLINE_DWORD_FLIP(out, in)


//
//  Inline byte flip and write to packet (unaligned)
//

#define INLINE_WRITE_FLIPPED_WORD( pout, in ) \
            INLINE_WORD_FLIP( *((UNALIGNED WORD *)(pout)), in )

#define INLINE_WRITE_FLIPPED_DWORD( pout, in ) \
            INLINE_DWORD_FLIP( *((UNALIGNED DWORD *)(pout)), in )




//
//  Basic DNS definitions
//

//
//  DNS port for both UDP and TCP is 53.
//

#define DNS_PORT_HOST_ORDER     (0x0035)    // port 53
#define DNS_PORT_NET_ORDER      (0x3500)

//
//  DNS UDP packets no more than 512 bytes
//

#define DNS_RFC_MAX_UDP_PACKET_LENGTH   (512)


//
//  DNS Names limited to 255, 63 in any one label
//

#define DNS_MAX_NAME_LENGTH             (255)
#define DNS_MAX_LABEL_LENGTH            (63)
#define DNS_MAX_NAME_BUFFER_LENGTH      (256)
#define DNS_MAX_LABEL_BUFFER_LENGTH     (64)

//
//  Reverse lookup domain names
//

#define DNS_IP4_REVERSE_DOMAIN_STRING_A     ("in-addr.arpa.")
#define DNS_IP4_REVERSE_DOMAIN_STRING_W     (L"in-addr.arpa.")

#define DNS_MAX_IP4_REVERSE_NAME_LENGTH     (IP4_ADDRESS_STRING_LENGTH+15)
            //(IP4_ADDRESS_STRING_LENGTH+1+sizeof(DNS_IP4_REVERSE_DOMAIN_STRING_A))

#define DNS_IP6_REVERSE_DOMAIN_STRING_A     ("ip6.arpa.")
#define DNS_IP6_REVERSE_DOMAIN_STRING_W     (L"ip6.arpa.")

#define DNS_MAX_IP6_REVERSE_NAME_LENGTH     (75)
            //(64+sizeof(DNS_IP6_REVERSE_DOMAIN_STRING_A))

//  Combined

#define DNS_MAX_REVERSE_NAME_LENGTH     DNS_MAX_IP6_REVERSE_NAME_LENGTH

#ifdef UNICODE
#define DNS_IP4_REVERSE_DOMAIN_STRING   DNS_IP4_REVERSE_DOMAIN_STRING_W
#define DNS_IP6_REVERSE_DOMAIN_STRING   DNS_IP6_REVERSE_DOMAIN_STRING_W
#else
#define DNS_IP4_REVERSE_DOMAIN_STRING   DNS_IP4_REVERSE_DOMAIN_STRING_A
#define DNS_IP6_REVERSE_DOMAIN_STRING   DNS_IP6_REVERSE_DOMAIN_STRING_A
#endif

//
//  Backcompat only -- name def contains terminating NULL
//

#define DNS_MAX_IP4_REVERSE_NAME_BUFFER_LENGTH  DNS_MAX_IP4_REVERSE_NAME_LENGTH
#define DNS_MAX_IP6_REVERSE_NAME_BUFFER_LENGTH  DNS_MAX_IP6_REVERSE_NAME_LENGTH
#define DNS_MAX_REVERSE_NAME_BUFFER_LENGTH      DNS_MAX_REVERSE_NAME_LENGTH


//
//  DNS Text string limited by size representable
//      in a single byte length field

#define DNS_MAX_TEXT_STRING_LENGTH  (255)




//
//  DNS On-The-Wire Structures
//

#pragma pack(push, 1)

//
//  DNS Message Header
//

typedef struct _DNS_HEADER
{
    WORD    Xid;

    BYTE    RecursionDesired : 1;
    BYTE    Truncation : 1;
    BYTE    Authoritative : 1;
    BYTE    Opcode : 4;
    BYTE    IsResponse : 1;

    BYTE    ResponseCode : 4;
    BYTE    CheckingDisabled : 1;
    BYTE    AuthenticatedData : 1;
    BYTE    Reserved : 1;
    BYTE    RecursionAvailable : 1;

    WORD    QuestionCount;
    WORD    AnswerCount;
    WORD    NameServerCount;
    WORD    AdditionalCount;
}
DNS_HEADER, *PDNS_HEADER;

typedef struct _DNS_HEADER_EXT
{
    WORD            Reserved : 15;
    WORD            DnssecOk : 1;
    BYTE            chRcode;
    BYTE            chVersion;
}
DNS_HEADER_EXT, *PDNS_HEADER_EXT;

//
//  Flags as WORD
//

#define DNS_HEADER_FLAGS(pHead)     ( *((PWORD)(pHead)+1) )


//
//  Byte flip DNS header to\from host order.
//
//  Note that this does NOT flip flags, as definition above defines
//  flags as individual bytes for direct access to net byte order.
//

#define DNS_BYTE_FLIP_HEADER_COUNTS(pHeader)       \
        {                                   \
            PDNS_HEADER _head = (pHeader);  \
            INLINE_HTONS(_head->Xid,            _head->Xid             ); \
            INLINE_HTONS(_head->QuestionCount,  _head->QuestionCount   ); \
            INLINE_HTONS(_head->AnswerCount,    _head->AnswerCount     ); \
            INLINE_HTONS(_head->NameServerCount,_head->NameServerCount ); \
            INLINE_HTONS(_head->AdditionalCount,_head->AdditionalCount ); \
        }

//
//  Question name follows header
//

#define DNS_OFFSET_TO_QUESTION_NAME     sizeof(DNS_HEADER)

//
//  Question immediately follows header so compressed question name
//      0xC000 | sizeof(DNS_HEADER)

#define DNS_COMPRESSED_QUESTION_NAME  (0xC00C)


//
//  Packet extraction macros
//

#define DNS_QUESTION_NAME_FROM_HEADER( _pHeader_ ) \
            ( (PCHAR)( (PDNS_HEADER)(_pHeader_) + 1 ) )

#define DNS_ANSWER_FROM_QUESTION( _pQuestion_ ) \
            ( (PCHAR)( (PDNS_QUESTION)(_pQuestion_) + 1 ) )


//
//  DNS Question
//

typedef struct _DNS_WIRE_QUESTION
{
    //  Preceded by question name

    WORD    QuestionType;
    WORD    QuestionClass;
}
DNS_WIRE_QUESTION, *PDNS_WIRE_QUESTION;


//
//  DNS Resource Record
//

typedef struct _DNS_WIRE_RECORD
{
    //  Preceded by record owner name

    WORD    RecordType;
    WORD    RecordClass;
    DWORD   TimeToLive;
    WORD    DataLength;

    //  Followed by record data
}
DNS_WIRE_RECORD, *PDNS_WIRE_RECORD;

#pragma pack(pop)


//
//  DNS Query Types
//

#define DNS_OPCODE_QUERY            0   // Query
#define DNS_OPCODE_IQUERY           1   // Obsolete: IP to name
#define DNS_OPCODE_SERVER_STATUS    2   // Obsolete: DNS ping
#define DNS_OPCODE_UNKNOWN          3   // Unknown
#define DNS_OPCODE_NOTIFY           4   // Notify
#define DNS_OPCODE_UPDATE           5   // Dynamic Update

//
//  DNS response codes.
//
//  Sent in the "ResponseCode" field of a DNS_HEADER.
//

#define DNS_RCODE_NOERROR       0
#define DNS_RCODE_FORMERR       1       // Format error
#define DNS_RCODE_SERVFAIL      2       // Server failure
#define DNS_RCODE_NXDOMAIN      3       // Name error
#define DNS_RCODE_NOTIMPL       4       // Not implemented
#define DNS_RCODE_REFUSED       5       // Refused
#define DNS_RCODE_YXDOMAIN      6       // Domain name should not exist
#define DNS_RCODE_YXRRSET       7       // RR set should not exist
#define DNS_RCODE_NXRRSET       8       // RR set does not exist
#define DNS_RCODE_NOTAUTH       9       // Not authoritative for zone
#define DNS_RCODE_NOTZONE       10      // Name is not zone
#define DNS_RCODE_MAX           15

//
//  Extended RCODEs
//

#define DNS_RCODE_BADVERS       16      // Bad EDNS version
#define DNS_RCODE_BADSIG        16      // Bad signature
#define DNS_RCODE_BADKEY        17      // Bad key
#define DNS_RCODE_BADTIME       18      // Bad timestamp

//
//  Mappings to friendly names
//

#define DNS_RCODE_NO_ERROR          DNS_RCODE_NOERROR
#define DNS_RCODE_FORMAT_ERROR      DNS_RCODE_FORMERR
#define DNS_RCODE_SERVER_FAILURE    DNS_RCODE_SERVFAIL
#define DNS_RCODE_NAME_ERROR        DNS_RCODE_NXDOMAIN
#define DNS_RCODE_NOT_IMPLEMENTED   DNS_RCODE_NOTIMPL


//
//  DNS Classes
//
//  Classes are on the wire as WORDs.
//
//  _CLASS_ defines in host order.
//  _RCLASS_ defines in net byte order.
//
//  Generally we'll avoid byte flip and test class in net byte order.
//

#define DNS_CLASS_INTERNET  0x0001      //  1
#define DNS_CLASS_CSNET     0x0002      //  2
#define DNS_CLASS_CHAOS     0x0003      //  3
#define DNS_CLASS_HESIOD    0x0004      //  4
#define DNS_CLASS_NONE      0x00fe      //  254
#define DNS_CLASS_ALL       0x00ff      //  255
#define DNS_CLASS_ANY       0x00ff      //  255
#define DNS_CLASS_UNICAST_RESPONSE   0x8000  // Set the top-bit of the field to one

#define DNS_RCLASS_INTERNET 0x0100      //  1
#define DNS_RCLASS_CSNET    0x0200      //  2
#define DNS_RCLASS_CHAOS    0x0300      //  3
#define DNS_RCLASS_HESIOD   0x0400      //  4
#define DNS_RCLASS_NONE     0xfe00      //  254
#define DNS_RCLASS_ALL      0xff00      //  255
#define DNS_RCLASS_ANY      0xff00      //  255
#define DNS_RCLASS_UNICAST_RESPONSE   0x0080  // Set the top-bit of the field to one, in net order!


//
//  DNS Record Types
//
//  _TYPE_ defines are in host byte order.
//  _RTYPE_ defines are in net byte order.
//
//  Generally always deal with types in host byte order as we index
//  resource record functions by type.
//

#define DNS_TYPE_ZERO       0x0000

//  RFC 1034/1035
#define DNS_TYPE_A          0x0001      //  1
#define DNS_TYPE_NS         0x0002      //  2
#define DNS_TYPE_MD         0x0003      //  3
#define DNS_TYPE_MF         0x0004      //  4
#define DNS_TYPE_CNAME      0x0005      //  5
#define DNS_TYPE_SOA        0x0006      //  6
#define DNS_TYPE_MB         0x0007      //  7
#define DNS_TYPE_MG         0x0008      //  8
#define DNS_TYPE_MR         0x0009      //  9
#define DNS_TYPE_NULL       0x000a      //  10
#define DNS_TYPE_WKS        0x000b      //  11
#define DNS_TYPE_PTR        0x000c      //  12
#define DNS_TYPE_HINFO      0x000d      //  13
#define DNS_TYPE_MINFO      0x000e      //  14
#define DNS_TYPE_MX         0x000f      //  15
#define DNS_TYPE_TEXT       0x0010      //  16

//  RFC 1183
#define DNS_TYPE_RP         0x0011      //  17
#define DNS_TYPE_AFSDB      0x0012      //  18
#define DNS_TYPE_X25        0x0013      //  19
#define DNS_TYPE_ISDN       0x0014      //  20
#define DNS_TYPE_RT         0x0015      //  21

//  RFC 1348
#define DNS_TYPE_NSAP       0x0016      //  22
#define DNS_TYPE_NSAPPTR    0x0017      //  23

//  RFC 2065    (DNS security)
#define DNS_TYPE_SIG        0x0018      //  24
#define DNS_TYPE_KEY        0x0019      //  25

//  RFC 1664    (X.400 mail)
#define DNS_TYPE_PX         0x001a      //  26

//  RFC 1712    (Geographic position)
#define DNS_TYPE_GPOS       0x001b      //  27

//  RFC 1886    (IPv6 Address)
#define DNS_TYPE_AAAA       0x001c      //  28

//  RFC 1876    (Geographic location)
#define DNS_TYPE_LOC        0x001d      //  29

//  RFC 2065    (Secure negative response)
#define DNS_TYPE_NXT        0x001e      //  30

//  Patton      (Endpoint Identifier)
#define DNS_TYPE_EID        0x001f      //  31

//  Patton      (Nimrod Locator)
#define DNS_TYPE_NIMLOC     0x0020      //  32

//  RFC 2052    (Service location)
#define DNS_TYPE_SRV        0x0021      //  33

//  ATM Standard something-or-another (ATM Address)
#define DNS_TYPE_ATMA       0x0022      //  34

//  RFC 2168    (Naming Authority Pointer)
#define DNS_TYPE_NAPTR      0x0023      //  35

//  RFC 2230    (Key Exchanger)
#define DNS_TYPE_KX         0x0024      //  36

//  RFC 2538    (CERT)
#define DNS_TYPE_CERT       0x0025      //  37

//  A6 Draft    (A6)
#define DNS_TYPE_A6         0x0026      //  38

//  DNAME Draft (DNAME)
#define DNS_TYPE_DNAME      0x0027      //  39

//  Eastlake    (Kitchen Sink)
#define DNS_TYPE_SINK       0x0028      //  40

//  RFC 2671    (EDNS OPT)
#define DNS_TYPE_OPT        0x0029      //  41

//  RFC 4034    (DNSSEC DS)
#define DNS_TYPE_DS         0x002b      //  43

//  RFC 4034    (DNSSEC RRSIG)
#define DNS_TYPE_RRSIG      0x002e      //  46

//  RFC 4034    (DNSSEC NSEC)
#define DNS_TYPE_NSEC       0x002f      //  47

//  RFC 4034    (DNSSEC DNSKEY)
#define DNS_TYPE_DNSKEY     0x0030      //  48

//  RFC 4701    (DHCID)
#define DNS_TYPE_DHCID      0x0031      //  49

//  RFC 5155    (DNSSEC NSEC3)
#define DNS_TYPE_NSEC3      0x0032      //  50

//  RFC 5155    (DNSSEC NSEC3PARAM)
#define DNS_TYPE_NSEC3PARAM 0x0033      //  51

//RFC 6698	(TLSA)
#define DNS_TYPE_TLSA	    0x0034      //  52

//
//  IANA Reserved
//

#define DNS_TYPE_UINFO      0x0064      //  100
#define DNS_TYPE_UID        0x0065      //  101
#define DNS_TYPE_GID        0x0066      //  102
#define DNS_TYPE_UNSPEC     0x0067      //  103

//
//  Query only types (1035, 1995)
//      - Crawford      (ADDRS)
//      - TKEY draft    (TKEY)
//      - TSIG draft    (TSIG)
//      - RFC 1995      (IXFR)
//      - RFC 1035      (AXFR up)
//

#define DNS_TYPE_ADDRS      0x00f8      //  248
#define DNS_TYPE_TKEY       0x00f9      //  249
#define DNS_TYPE_TSIG       0x00fa      //  250
#define DNS_TYPE_IXFR       0x00fb      //  251
#define DNS_TYPE_AXFR       0x00fc      //  252
#define DNS_TYPE_MAILB      0x00fd      //  253
#define DNS_TYPE_MAILA      0x00fe      //  254
#define DNS_TYPE_ALL        0x00ff      //  255
#define DNS_TYPE_ANY        0x00ff      //  255

//
//  Private use Microsoft types --  See www.iana.org/assignments/dns-parameters
//

#define DNS_TYPE_WINS       0xff01      //  64K - 255
#define DNS_TYPE_WINSR      0xff02      //  64K - 254
#define DNS_TYPE_NBSTAT     (DNS_TYPE_WINSR)

//
//  DNS Record Types -- Net Byte Order
//

#define DNS_RTYPE_A              0x0100  //  1
#define DNS_RTYPE_NS             0x0200  //  2
#define DNS_RTYPE_MD             0x0300  //  3
#define DNS_RTYPE_MF             0x0400  //  4
#define DNS_RTYPE_CNAME          0x0500  //  5
#define DNS_RTYPE_SOA            0x0600  //  6
#define DNS_RTYPE_MB             0x0700  //  7
#define DNS_RTYPE_MG             0x0800  //  8
#define DNS_RTYPE_MR             0x0900  //  9
#define DNS_RTYPE_NULL           0x0a00  //  10
#define DNS_RTYPE_WKS            0x0b00  //  11
#define DNS_RTYPE_PTR            0x0c00  //  12
#define DNS_RTYPE_HINFO          0x0d00  //  13
#define DNS_RTYPE_MINFO          0x0e00  //  14
#define DNS_RTYPE_MX             0x0f00  //  15
#define DNS_RTYPE_TEXT           0x1000  //  16
#define DNS_RTYPE_RP             0x1100  //  17
#define DNS_RTYPE_AFSDB          0x1200  //  18
#define DNS_RTYPE_X25            0x1300  //  19
#define DNS_RTYPE_ISDN           0x1400  //  20
#define DNS_RTYPE_RT             0x1500  //  21
#define DNS_RTYPE_NSAP           0x1600  //  22
#define DNS_RTYPE_NSAPPTR        0x1700  //  23
#define DNS_RTYPE_SIG            0x1800  //  24
#define DNS_RTYPE_KEY            0x1900  //  25
#define DNS_RTYPE_PX             0x1a00  //  26
#define DNS_RTYPE_GPOS           0x1b00  //  27
#define DNS_RTYPE_AAAA           0x1c00  //  28
#define DNS_RTYPE_LOC            0x1d00  //  29
#define DNS_RTYPE_NXT            0x1e00  //  30
#define DNS_RTYPE_EID            0x1f00  //  31
#define DNS_RTYPE_NIMLOC         0x2000  //  32
#define DNS_RTYPE_SRV            0x2100  //  33
#define DNS_RTYPE_ATMA           0x2200  //  34
#define DNS_RTYPE_NAPTR          0x2300  //  35
#define DNS_RTYPE_KX             0x2400  //  36
#define DNS_RTYPE_CERT           0x2500  //  37
#define DNS_RTYPE_A6             0x2600  //  38
#define DNS_RTYPE_DNAME          0x2700  //  39
#define DNS_RTYPE_SINK           0x2800  //  40
#define DNS_RTYPE_OPT            0x2900  //  41

#define DNS_RTYPE_DS             0x2b00  //  43
#define DNS_RTYPE_RRSIG          0x2e00  //  46
#define DNS_RTYPE_NSEC           0x2f00  //  47
#define DNS_RTYPE_DNSKEY         0x3000  //  48
#define DNS_RTYPE_DHCID          0x3100  //  49
#define DNS_RTYPE_NSEC3          0x3200  //  50
#define DNS_RTYPE_NSEC3PARAM     0x3300  //  51
#define DNS_RTYPE_TLSA	    	 0x3400	 //  52

//
//  IANA Reserved
//

#define DNS_RTYPE_UINFO          0x6400  //  100
#define DNS_RTYPE_UID            0x6500  //  101
#define DNS_RTYPE_GID            0x6600  //  102
#define DNS_RTYPE_UNSPEC         0x6700  //  103

//
//  Query only types
//

#define DNS_RTYPE_TKEY           0xf900  //  249
#define DNS_RTYPE_TSIG           0xfa00  //  250
#define DNS_RTYPE_IXFR           0xfb00  //  251
#define DNS_RTYPE_AXFR           0xfc00  //  252
#define DNS_RTYPE_MAILB          0xfd00  //  253
#define DNS_RTYPE_MAILA          0xfe00  //  254
#define DNS_RTYPE_ALL            0xff00  //  255
#define DNS_RTYPE_ANY            0xff00  //  255

//
//  Private use Microsoft types --  See www.iana.org/assignments/dns-parameters
//

#define DNS_RTYPE_WINS           0x01ff  //  64K - 255
#define DNS_RTYPE_WINSR          0x02ff  //  64K - 254

//
//  Record type specific definitions
//

//
//  ATMA (ATM address type) formats
//
//  Define these directly for any environment (ex NT4)
//  without winsock2 ATM support (ws2atm.h)
//

#ifndef  ATMA_E164
#define DNS_ATMA_FORMAT_E164            1
#define DNS_ATMA_FORMAT_AESA            2
#define DNS_ATMA_MAX_ADDR_LENGTH        (20)
#else
#define DNS_ATMA_FORMAT_E164            ATM_E164
#define DNS_ATMA_FORMAT_AESA            ATM_AESA
#define DNS_ATMA_MAX_ADDR_LENGTH        ATM_ADDR_SIZE
#endif

#define DNS_ATMA_AESA_ADDR_LENGTH       (20)
#define DNS_ATMA_MAX_RECORD_LENGTH      (DNS_ATMA_MAX_ADDR_LENGTH+1)


//
//  DNSSEC defs
//

//  DNSSEC algorithms

#define DNSSEC_ALGORITHM_RSAMD5                 1
#define DNSSEC_ALGORITHM_RSASHA1                5
#define DNSSEC_ALGORITHM_RSASHA1_NSEC3          7
#define DNSSEC_ALGORITHM_RSASHA256              8
#define DNSSEC_ALGORITHM_RSASHA512              10
#define DNSSEC_ALGORITHM_ECDSAP256_SHA256    	13
#define DNSSEC_ALGORITHM_ECDSAP384_SHA384    	14
#define DNSSEC_ALGORITHM_NULL					253
#define DNSSEC_ALGORITHM_PRIVATE				254

//  DNSSEC DS record digest algorithms

#define DNSSEC_DIGEST_ALGORITHM_SHA1            1
#define DNSSEC_DIGEST_ALGORITHM_SHA256          2
#define DNSSEC_DIGEST_ALGORITHM_SHA384          4

//  DNSSEC KEY protocol table

#define DNSSEC_PROTOCOL_NONE        0
#define DNSSEC_PROTOCOL_TLS         1
#define DNSSEC_PROTOCOL_EMAIL       2
#define DNSSEC_PROTOCOL_DNSSEC      3
#define DNSSEC_PROTOCOL_IPSEC       4

//  DNSSEC KEY flag field

#define DNSSEC_KEY_FLAG_NOAUTH          0x0001
#define DNSSEC_KEY_FLAG_NOCONF          0x0002
#define DNSSEC_KEY_FLAG_FLAG2           0x0004
#define DNSSEC_KEY_FLAG_EXTEND          0x0008
#define DNSSEC_KEY_FLAG_
#define DNSSEC_KEY_FLAG_FLAG4           0x0010
#define DNSSEC_KEY_FLAG_FLAG5           0x0020

// bits 6,7 are name type

#define DNSSEC_KEY_FLAG_USER            0x0000
#define DNSSEC_KEY_FLAG_ZONE            0x0040
#define DNSSEC_KEY_FLAG_HOST            0x0080
#define DNSSEC_KEY_FLAG_NTPE3           0x00c0

// bits 8-11 are reserved for future use

#define DNSSEC_KEY_FLAG_FLAG8           0x0100
#define DNSSEC_KEY_FLAG_FLAG9           0x0200
#define DNSSEC_KEY_FLAG_FLAG10          0x0400
#define DNSSEC_KEY_FLAG_FLAG11          0x0800

// bits 12-15 are sig field

#define DNSSEC_KEY_FLAG_SIG0            0x0000
#define DNSSEC_KEY_FLAG_SIG1            0x1000
#define DNSSEC_KEY_FLAG_SIG2            0x2000
#define DNSSEC_KEY_FLAG_SIG3            0x3000
#define DNSSEC_KEY_FLAG_SIG4            0x4000
#define DNSSEC_KEY_FLAG_SIG5            0x5000
#define DNSSEC_KEY_FLAG_SIG6            0x6000
#define DNSSEC_KEY_FLAG_SIG7            0x7000
#define DNSSEC_KEY_FLAG_SIG8            0x8000
#define DNSSEC_KEY_FLAG_SIG9            0x9000
#define DNSSEC_KEY_FLAG_SIG10           0xa000
#define DNSSEC_KEY_FLAG_SIG11           0xb000
#define DNSSEC_KEY_FLAG_SIG12           0xc000
#define DNSSEC_KEY_FLAG_SIG13           0xd000
#define DNSSEC_KEY_FLAG_SIG14           0xe000
#define DNSSEC_KEY_FLAG_SIG15           0xf000


//
//  TKEY modes
//

#define DNS_TKEY_MODE_SERVER_ASSIGN         1
#define DNS_TKEY_MODE_DIFFIE_HELLMAN        2
#define DNS_TKEY_MODE_GSS                   3
#define DNS_TKEY_MODE_RESOLVER_ASSIGN       4

//
//  WINS + NBSTAT flag field
//

#define DNS_WINS_FLAG_SCOPE     (0x80000000)
#define DNS_WINS_FLAG_LOCAL     (0x00010000)


//
//  Helpful checks
//

#define IS_WORD_ALIGNED(p)      ( !((UINT_PTR)(p) & (UINT_PTR)1) )
#define IS_DWORD_ALIGNED(p)     ( !((UINT_PTR)(p) & (UINT_PTR)3) )
#define IS_QWORD_ALIGNED(p)     ( !((UINT_PTR)(p) & (UINT_PTR)7) )




//
//  DNS config API
//

//
//  Types of DNS configuration info
//

typedef enum
{
    //  In Win2K
    DnsConfigPrimaryDomainName_W,
    DnsConfigPrimaryDomainName_A,
    DnsConfigPrimaryDomainName_UTF8,

    //  Not available yet
    DnsConfigAdapterDomainName_W,
    DnsConfigAdapterDomainName_A,
    DnsConfigAdapterDomainName_UTF8,

    //  In Win2K
    DnsConfigDnsServerList,

    //  Not available yet
    DnsConfigSearchList,
    DnsConfigAdapterInfo,

    //  In Win2K
    DnsConfigPrimaryHostNameRegistrationEnabled,
    DnsConfigAdapterHostNameRegistrationEnabled,
    DnsConfigAddressRegistrationMaxCount,

    //  In WindowsXP
    DnsConfigHostName_W,
    DnsConfigHostName_A,
    DnsConfigHostName_UTF8,
    DnsConfigFullHostName_W,
    DnsConfigFullHostName_A,
    DnsConfigFullHostName_UTF8,

    DnsConfigNameServer
}
DNS_CONFIG_TYPE;

//
//  Config API flags
//

//
//  DNS_CONFIG_FLAG_ALLOC -- Causes config info to be allocated.
//      Free with LocalFree().
//
#define DNS_CONFIG_FLAG_ALLOC   (0x00000001)

DNS_STATUS
WINAPI
DnsQueryConfig(
    _In_                                      DNS_CONFIG_TYPE     Config,
    _In_                                      DWORD               Flag,
    _In_opt_                                  PCWSTR              pwsAdapterName,
    _In_opt_                                  PVOID               pReserved,
    _Out_writes_bytes_to_opt_(*pBufLen, *pBufLen) PVOID               pBuffer,
    _Inout_                                   PDWORD              pBufLen
    );

//
//  DNS resource record structure
//

//
//  Record data for specific types
//

typedef struct
{
    IP4_ADDRESS     IpAddress;
}
DNS_A_DATA, *PDNS_A_DATA;

typedef struct
{
    PWSTR           pNameHost;
}
DNS_PTR_DATAW, *PDNS_PTR_DATAW;

typedef struct
{
    PSTR            pNameHost;
}
DNS_PTR_DATAA, *PDNS_PTR_DATAA;

typedef struct
{
    PWSTR           pNamePrimaryServer;
    PWSTR           pNameAdministrator;
    DWORD           dwSerialNo;
    DWORD           dwRefresh;
    DWORD           dwRetry;
    DWORD           dwExpire;
    DWORD           dwDefaultTtl;
}
DNS_SOA_DATAW, *PDNS_SOA_DATAW;

typedef struct
{
    PSTR            pNamePrimaryServer;
    PSTR            pNameAdministrator;
    DWORD           dwSerialNo;
    DWORD           dwRefresh;
    DWORD           dwRetry;
    DWORD           dwExpire;
    DWORD           dwDefaultTtl;
}
DNS_SOA_DATAA, *PDNS_SOA_DATAA;

typedef struct
{
    PWSTR           pNameMailbox;
    PWSTR           pNameErrorsMailbox;
}
DNS_MINFO_DATAW, *PDNS_MINFO_DATAW;

typedef struct
{
    PSTR            pNameMailbox;
    PSTR            pNameErrorsMailbox;
}
DNS_MINFO_DATAA, *PDNS_MINFO_DATAA;

typedef struct
{
    PWSTR           pNameExchange;
    WORD            wPreference;
    WORD            Pad;        // keep ptrs DWORD aligned
}
DNS_MX_DATAW, *PDNS_MX_DATAW;

typedef struct
{
    PSTR            pNameExchange;
    WORD            wPreference;
    WORD            Pad;        // keep ptrs DWORD aligned
}
DNS_MX_DATAA, *PDNS_MX_DATAA;

typedef struct
{
    DWORD           dwStringCount;
#ifdef MIDL_PASS
    [size_is(dwStringCount)] PWSTR pStringArray[];
#else
    PWSTR           pStringArray[1];
#endif
}
DNS_TXT_DATAW, *PDNS_TXT_DATAW;

typedef struct
{
    DWORD           dwStringCount;
#ifdef MIDL_PASS
    [size_is(dwStringCount)] PSTR  pStringArray[];
#else
    PSTR            pStringArray[1];
#endif
}
DNS_TXT_DATAA, *PDNS_TXT_DATAA;

typedef struct
{
    DWORD           dwByteCount;
#ifdef MIDL_PASS
    [size_is(dwByteCount)] BYTE Data[];
#else
    BYTE            Data[1];
#endif
}
DNS_NULL_DATA, *PDNS_NULL_DATA;

typedef struct
{
    IP4_ADDRESS     IpAddress;
    UCHAR           chProtocol;
    BYTE            BitMask[1];
}
DNS_WKS_DATA, *PDNS_WKS_DATA;

typedef struct
{
    IP6_ADDRESS     Ip6Address;
}
DNS_AAAA_DATA, *PDNS_AAAA_DATA;

typedef struct
{
    WORD            wTypeCovered;
    BYTE            chAlgorithm;
    BYTE            chLabelCount;
    DWORD           dwOriginalTtl;
    DWORD           dwExpiration;
    DWORD           dwTimeSigned;
    WORD            wKeyTag;
    WORD            wSignatureLength;
    PWSTR           pNameSigner;
#ifdef MIDL_PASS
    [size_is(wSignatureLength)] BYTE  Signature[];
#else
    BYTE            Signature[1];
#endif
}
DNS_SIG_DATAW, *PDNS_SIG_DATAW, DNS_RRSIG_DATAW, *PDNS_RRSIG_DATAW;

typedef struct
{
    WORD            wTypeCovered;
    BYTE            chAlgorithm;
    BYTE            chLabelCount;
    DWORD           dwOriginalTtl;
    DWORD           dwExpiration;
    DWORD           dwTimeSigned;
    WORD            wKeyTag;
    WORD            wSignatureLength;
    PSTR            pNameSigner;
#ifdef MIDL_PASS
    [size_is(wSignatureLength)] BYTE  Signature[];
#else
    BYTE            Signature[1];
#endif
}
DNS_SIG_DATAA, *PDNS_SIG_DATAA, DNS_RRSIG_DATAA, *PDNS_RRSIG_DATAA;

typedef struct
{
    WORD            wFlags;
    BYTE            chProtocol;
    BYTE            chAlgorithm;
    WORD            wKeyLength;
    WORD            wPad;            // keep byte field aligned
#ifdef MIDL_PASS
    [size_is(wKeyLength)] BYTE Key[];
#else
    BYTE            Key[1];
#endif
}
DNS_KEY_DATA, *PDNS_KEY_DATA, DNS_DNSKEY_DATA, *PDNS_DNSKEY_DATA;

typedef struct
{
    DWORD           dwByteCount;
#ifdef MIDL_PASS
    [size_is(dwByteCount)] BYTE DHCID[];
#else
    BYTE            DHCID[1];
#endif
}
DNS_DHCID_DATA, *PDNS_DHCID_DATA;

typedef struct
{
    PWSTR           pNextDomainName;
    WORD            wTypeBitMapsLength;
    WORD            wPad;            // keep byte field aligned
#ifdef MIDL_PASS
    [size_is(wTypeBitMapsLength)] BYTE  TypeBitMaps[];
#else
    BYTE            TypeBitMaps[1];
#endif
}
DNS_NSEC_DATAW, *PDNS_NSEC_DATAW;

typedef struct
{
    PSTR            pNextDomainName;
    WORD            wTypeBitMapsLength;
    WORD            wPad;            // keep byte field aligned
#ifdef MIDL_PASS
    [size_is(wTypeBitMapsLength)] BYTE  TypeBitMaps[];
#else
    BYTE            TypeBitMaps[1];
#endif
}
DNS_NSEC_DATAA, *PDNS_NSEC_DATAA;

typedef struct
{
    BYTE            chAlgorithm;
    BYTE            bFlags;
    WORD            wIterations;
    BYTE            bSaltLength;
    BYTE            bHashLength;
    WORD            wTypeBitMapsLength;
#ifdef MIDL_PASS
    [size_is(bSaltLength+bHashLength+wTypeBitMapsLength)] BYTE  chData[];
#else
    BYTE            chData[1];
#endif
}
DNS_NSEC3_DATA, *PDNS_NSEC3_DATA;

typedef struct
{
    BYTE            chAlgorithm;
    BYTE            bFlags;
    WORD            wIterations;
    BYTE            bSaltLength;
    BYTE            bPad[3];        // keep salt field aligned
#ifdef MIDL_PASS
    [size_is(bSaltLength)] BYTE  pbSalt[];
#else
    BYTE            pbSalt[1];
#endif
}
DNS_NSEC3PARAM_DATA, *PDNS_NSEC3PARAM_DATA;

typedef struct
{
    BYTE            bCertUsage;
    BYTE            bSelector;
    BYTE            bMatchingType;
    WORD            bCertificateAssociationDataLength;
    BYTE            bPad[3];        // keep certificate association data field aligned
#ifdef MIDL_PASS
    [size_is(bCertificateAssociationDataLength)] BYTE  bCertificateAssociationData[];
#else
    BYTE            bCertificateAssociationData[1];
#endif
}
DNS_TLSA_DATA, *PDNS_TLSA_DATA;

typedef struct
{
    WORD            wKeyTag;
    BYTE            chAlgorithm;
    BYTE            chDigestType;
    WORD            wDigestLength;
    WORD            wPad;            // keep byte field aligned
#ifdef MIDL_PASS
    [size_is(wDigestLength)] BYTE  Digest[];
#else
    BYTE            Digest[1];
#endif
}
DNS_DS_DATA, *PDNS_DS_DATA;

typedef struct
{
    WORD            wDataLength;
    WORD            wPad;            // keep byte field aligned
#ifdef MIDL_PASS
    [size_is(wDataLength)] BYTE Data[];
#else
    BYTE            Data[1];
#endif
}
DNS_OPT_DATA, *PDNS_OPT_DATA;

typedef struct
{
    WORD            wVersion;
    WORD            wSize;
    WORD            wHorPrec;
    WORD            wVerPrec;
    DWORD           dwLatitude;
    DWORD           dwLongitude;
    DWORD           dwAltitude;
}
DNS_LOC_DATA, *PDNS_LOC_DATA;

typedef struct
{
    PWSTR           pNameNext;
    WORD            wNumTypes;
#ifdef MIDL_PASS
    [size_is(wNumTypes)] WORD wTypes[];
#else
    WORD            wTypes[1];
#endif
}
DNS_NXT_DATAW, *PDNS_NXT_DATAW;

typedef struct
{
    PSTR            pNameNext;
    WORD            wNumTypes;
#ifdef MIDL_PASS
    [size_is(wNumTypes)] WORD wTypes[];
#else
    WORD            wTypes[1];
#endif
}
DNS_NXT_DATAA, *PDNS_NXT_DATAA;

typedef struct
{
    PWSTR           pNameTarget;
    WORD            wPriority;
    WORD            wWeight;
    WORD            wPort;
    WORD            Pad;            // keep ptrs DWORD aligned
}
DNS_SRV_DATAW, *PDNS_SRV_DATAW;

typedef struct
{
    PSTR            pNameTarget;
    WORD            wPriority;
    WORD            wWeight;
    WORD            wPort;
    WORD            Pad;            // keep ptrs DWORD aligned
}
DNS_SRV_DATAA, *PDNS_SRV_DATAA;

typedef struct
{
    WORD            wOrder;
    WORD            wPreference;
    PWSTR           pFlags;
    PWSTR           pService;
    PWSTR           pRegularExpression;
    PWSTR           pReplacement;
}
DNS_NAPTR_DATAW, *PDNS_NAPTR_DATAW;

typedef struct
{
    WORD            wOrder;
    WORD            wPreference;
    PSTR            pFlags;
    PSTR            pService;
    PSTR            pRegularExpression;
    PSTR            pReplacement;
}
DNS_NAPTR_DATAA, *PDNS_NAPTR_DATAA;



typedef struct
{
    BYTE            AddressType;
    BYTE            Address[ DNS_ATMA_MAX_ADDR_LENGTH ];

    //  E164 -- Null terminated string of less than
    //      DNS_ATMA_MAX_ADDR_LENGTH
    //
    //  For NSAP (AESA) BCD encoding of exactly
    //      DNS_ATMA_AESA_ADDR_LENGTH
}
DNS_ATMA_DATA, *PDNS_ATMA_DATA;


typedef struct
{
    PWSTR           pNameAlgorithm;
    PBYTE           pAlgorithmPacket;
    PBYTE           pKey;
    PBYTE           pOtherData;
    DWORD           dwCreateTime;
    DWORD           dwExpireTime;
    WORD            wMode;
    WORD            wError;
    WORD            wKeyLength;
    WORD            wOtherLength;
    UCHAR           cAlgNameLength;
    BOOL            bPacketPointers;
}
DNS_TKEY_DATAW, *PDNS_TKEY_DATAW;

typedef struct
{
    PSTR            pNameAlgorithm;
    PBYTE           pAlgorithmPacket;
    PBYTE           pKey;
    PBYTE           pOtherData;
    DWORD           dwCreateTime;
    DWORD           dwExpireTime;
    WORD            wMode;
    WORD            wError;
    WORD            wKeyLength;
    WORD            wOtherLength;
    UCHAR           cAlgNameLength;
    BOOL            bPacketPointers;
}
DNS_TKEY_DATAA, *PDNS_TKEY_DATAA;

typedef struct
{
    PWSTR           pNameAlgorithm;
    PBYTE           pAlgorithmPacket;
    PBYTE           pSignature;
    PBYTE           pOtherData;
    LONGLONG        i64CreateTime;
    WORD            wFudgeTime;
    WORD            wOriginalXid;
    WORD            wError;
    WORD            wSigLength;
    WORD            wOtherLength;
    UCHAR           cAlgNameLength;
    BOOL            bPacketPointers;
}
DNS_TSIG_DATAW, *PDNS_TSIG_DATAW;

typedef struct
{
    PSTR            pNameAlgorithm;
    PBYTE           pAlgorithmPacket;
    PBYTE           pSignature;
    PBYTE           pOtherData;
    LONGLONG        i64CreateTime;
    WORD            wFudgeTime;
    WORD            wOriginalXid;
    WORD            wError;
    WORD            wSigLength;
    WORD            wOtherLength;
    UCHAR           cAlgNameLength;
    BOOL            bPacketPointers;
}
DNS_TSIG_DATAA, *PDNS_TSIG_DATAA;

typedef struct
{
    DWORD           dwByteCount;
#ifdef MIDL_PASS
    [size_is(dwByteCount)] BYTE bData[];
#else
    BYTE            bData[1];
#endif
}
DNS_UNKNOWN_DATA, *PDNS_UNKNOWN_DATA;

//
//  MS only types -- only hit the wire in MS-MS zone transfer
//

typedef struct
{
    DWORD           dwMappingFlag;
    DWORD           dwLookupTimeout;
    DWORD           dwCacheTimeout;
    DWORD           cWinsServerCount;
    IP4_ADDRESS     WinsServers[1];
}
DNS_WINS_DATA, *PDNS_WINS_DATA;

typedef struct
{
    DWORD           dwMappingFlag;
    DWORD           dwLookupTimeout;
    DWORD           dwCacheTimeout;
    PWSTR           pNameResultDomain;
}
DNS_WINSR_DATAW, *PDNS_WINSR_DATAW;

typedef struct
{
    DWORD           dwMappingFlag;
    DWORD           dwLookupTimeout;
    DWORD           dwCacheTimeout;
    PSTR            pNameResultDomain;
}
DNS_WINSR_DATAA, *PDNS_WINSR_DATAA;

//
//  Unicode/ANSI record types
//

#ifdef UNICODE
typedef DNS_PTR_DATAW   DNS_PTR_DATA,   *PDNS_PTR_DATA;
typedef DNS_SOA_DATAW   DNS_SOA_DATA,   *PDNS_SOA_DATA;
typedef DNS_MINFO_DATAW DNS_MINFO_DATA, *PDNS_MINFO_DATA;
typedef DNS_MX_DATAW    DNS_MX_DATA,    *PDNS_MX_DATA;
typedef DNS_TXT_DATAW   DNS_TXT_DATA,   *PDNS_TXT_DATA;
typedef DNS_SIG_DATAW   DNS_SIG_DATA,   *PDNS_SIG_DATA;
typedef DNS_NXT_DATAW   DNS_NXT_DATA,   *PDNS_NXT_DATA;
typedef DNS_SRV_DATAW   DNS_SRV_DATA,   *PDNS_SRV_DATA;
typedef DNS_NAPTR_DATAW DNS_NAPTR_DATA, *PDNS_NAPTR_DATA;
typedef DNS_RRSIG_DATAW DNS_RRSIG_DATA, *PDNS_RRSIG_DATA;
typedef DNS_NSEC_DATAW  DNS_NSEC_DATA,  *PDNS_NSEC_DATA;
typedef DNS_TKEY_DATAW  DNS_TKEY_DATA,  *PDNS_TKEY_DATA;
typedef DNS_TSIG_DATAW  DNS_TSIG_DATA,  *PDNS_TSIG_DATA;
typedef DNS_WINSR_DATAW DNS_WINSR_DATA, *PDNS_WINSR_DATA;
#else
typedef DNS_PTR_DATAA   DNS_PTR_DATA,   *PDNS_PTR_DATA;
typedef DNS_SOA_DATAA   DNS_SOA_DATA,   *PDNS_SOA_DATA;
typedef DNS_MINFO_DATAA DNS_MINFO_DATA, *PDNS_MINFO_DATA;
typedef DNS_MX_DATAA    DNS_MX_DATA,    *PDNS_MX_DATA;
typedef DNS_TXT_DATAA   DNS_TXT_DATA,   *PDNS_TXT_DATA;
typedef DNS_SIG_DATAA   DNS_SIG_DATA,   *PDNS_SIG_DATA;
typedef DNS_NXT_DATAA   DNS_NXT_DATA,   *PDNS_NXT_DATA;
typedef DNS_SRV_DATAA   DNS_SRV_DATA,   *PDNS_SRV_DATA;
typedef DNS_NAPTR_DATAA DNS_NAPTR_DATA, *PDNS_NAPTR_DATA;
typedef DNS_RRSIG_DATAA DNS_RRSIG_DATA, *PDNS_RRSIG_DATA;
typedef DNS_NSEC_DATAA  DNS_NSEC_DATA,  *PDNS_NSEC_DATA;
typedef DNS_TKEY_DATAA  DNS_TKEY_DATA,  *PDNS_TKEY_DATA;
typedef DNS_TSIG_DATAA  DNS_TSIG_DATA,  *PDNS_TSIG_DATA;
typedef DNS_WINSR_DATAA DNS_WINSR_DATA, *PDNS_WINSR_DATA;
#endif

//
//  Length of non-fixed-length data types
//

#define DNS_TEXT_RECORD_LENGTH(StringCount) \
            (FIELD_OFFSET(DNS_TXT_DATA, pStringArray) + ((StringCount) * sizeof(PCHAR)))

#define DNS_NULL_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_NULL_DATA, Data) + (ByteCount))

#define DNS_WKS_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_WKS_DATA, BitMask) + (ByteCount))

#define DNS_WINS_RECORD_LENGTH(IpCount) \
            (FIELD_OFFSET(DNS_WINS_DATA, WinsServers) + ((IpCount) * sizeof(IP4_ADDRESS)))

#define DNS_KEY_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_KEY_DATA, Key) + (ByteCount))

#define DNS_SIG_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_SIG_DATA, Signature) + (ByteCount))

#define DNS_NSEC_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_NSEC_DATA, TypeBitMaps) + (ByteCount))

#define DNS_DS_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_DS_DATA, Digest) + (ByteCount))

#define DNS_OPT_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_OPT_DATA, Data) + (ByteCount))

#define DNS_DHCID_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_DHCID_DATA, DHCID) + (ByteCount))

#define DNS_NSEC3_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_NSEC3_DATA, chData) + (ByteCount))

#define DNS_NSEC3PARAM_RECORD_LENGTH(ByteCount) \
			(FIELD_OFFSET(DNS_NSEC3PARAM_DATA, pbSalt) + (ByteCount))

#define DNS_TLSA_RECORD_LENGTH(ByteCount) \
			(FIELD_OFFSET(DNS_TLSA_DATA, bCertificateAssociationData) + (ByteCount))

#define DNS_UNKNOWN_RECORD_LENGTH(ByteCount) \
            (FIELD_OFFSET(DNS_UNKNOWN_DATA, bData) + (ByteCount))

//
//  Record flags
//

typedef struct _DnsRecordFlags
{
    DWORD   Section     : 2;
    DWORD   Delete      : 1;
    DWORD   CharSet     : 2;
    DWORD   Unused      : 3;

    DWORD   Reserved    : 24;
}
DNS_RECORD_FLAGS;


//
//  Wire Record Sections
//
//  Useable both in record flags "Section" and as index into
//  wire message header section counts.
//

typedef enum _DnsSection
{
    DnsSectionQuestion,
    DnsSectionAnswer,
    DnsSectionAuthority,
    DnsSectionAddtional,
}
DNS_SECTION;

//  Update message section names

#define DnsSectionZone      DnsSectionQuestion
#define DnsSectionPrereq    DnsSectionAnswer
#define DnsSectionUpdate    DnsSectionAuthority


//
//  Record flags as bit flags
//  These may be or'd together to set the fields
//

//  RR Section in packet

#define     DNSREC_SECTION      (0x00000003)

#define     DNSREC_QUESTION     (0x00000000)
#define     DNSREC_ANSWER       (0x00000001)
#define     DNSREC_AUTHORITY    (0x00000002)
#define     DNSREC_ADDITIONAL   (0x00000003)

//  RR Section in packet (update)

#define     DNSREC_ZONE         (0x00000000)
#define     DNSREC_PREREQ       (0x00000001)
#define     DNSREC_UPDATE       (0x00000002)

//  Delete RR (update) or No-exist (prerequisite)

#define     DNSREC_DELETE       (0x00000004)
#define     DNSREC_NOEXIST      (0x00000004)


//
//  Record \ RR set structure
//
//  Note:  The dwReserved flag serves to insure that the substructures
//  start on 64-bit boundaries.  Do NOT pack this structure, as the
//  substructures may contain pointers or int64 values which are
//  properly aligned unpacked.
//

#ifdef MIDL_PASS

#define PDNS_RECORD     PVOID
#define PDNS_RECORDA    PVOID
#define PDNS_RECORDW    PVOID

#else

typedef _Struct_size_bytes_(FIELD_OFFSET(struct _DnsRecordW, Data) + wDataLength) struct _DnsRecordW
{
    struct _DnsRecordW *    pNext;
    PWSTR                   pName;
    WORD                    wType;
    WORD                    wDataLength;    // Not referenced for DNS record types
                                            // defined above.
    union
    {
        DWORD               DW;     // flags as DWORD
        DNS_RECORD_FLAGS    S;      // flags as structure

    } Flags;

    DWORD                   dwTtl;
    DWORD                   dwReserved;

    //  Record Data

    union
    {
        DNS_A_DATA          A;
        DNS_SOA_DATAW       SOA, Soa;
        DNS_PTR_DATAW       PTR, Ptr,
                            NS, Ns,
                            CNAME, Cname,
                            DNAME, Dname,
                            MB, Mb,
                            MD, Md,
                            MF, Mf,
                            MG, Mg,
                            MR, Mr;
        DNS_MINFO_DATAW     MINFO, Minfo,
                            RP, Rp;
        DNS_MX_DATAW        MX, Mx,
                            AFSDB, Afsdb,
                            RT, Rt;
        DNS_TXT_DATAW       HINFO, Hinfo,
                            ISDN, Isdn,
                            TXT, Txt,
                            X25;
        DNS_NULL_DATA       Null;
        DNS_WKS_DATA        WKS, Wks;
        DNS_AAAA_DATA       AAAA;
        DNS_KEY_DATA        KEY, Key;
        DNS_SIG_DATAW       SIG, Sig;
        DNS_ATMA_DATA       ATMA, Atma;
        DNS_NXT_DATAW       NXT, Nxt;
        DNS_SRV_DATAW       SRV, Srv;
        DNS_NAPTR_DATAW     NAPTR, Naptr;
        DNS_OPT_DATA        OPT, Opt;
        DNS_DS_DATA         DS, Ds;
        DNS_RRSIG_DATAW     RRSIG, Rrsig;
        DNS_NSEC_DATAW      NSEC, Nsec;
        DNS_DNSKEY_DATA     DNSKEY, Dnskey;
        DNS_TKEY_DATAW      TKEY, Tkey;
        DNS_TSIG_DATAW      TSIG, Tsig;
        DNS_WINS_DATA       WINS, Wins;
        DNS_WINSR_DATAW     WINSR, WinsR, NBSTAT, Nbstat;
        DNS_DHCID_DATA      DHCID;
        DNS_NSEC3_DATA      NSEC3, Nsec3;
        DNS_NSEC3PARAM_DATA	NSEC3PARAM, Nsec3Param;
        DNS_TLSA_DATA	    TLSA, Tlsa;
        DNS_UNKNOWN_DATA    UNKNOWN, Unknown;
        PBYTE               pDataPtr;

    } Data;
}
DNS_RECORDW, *PDNS_RECORDW;

typedef struct _DnsRecordOptW
{
    struct _DnsRecordW *    pNext;
    PWSTR                   pName;
    WORD                    wType;
    WORD                    wDataLength;    // Not referenced for DNS record types
                                            // defined above.
    union
    {
        DWORD               DW;     // flags as DWORD
        DNS_RECORD_FLAGS    S;      // flags as structure

    } Flags;

    DNS_HEADER_EXT          ExtHeader;      // TTL
    WORD                    wPayloadSize;   // dwReserved;
    WORD                    wReserved;

    //  Record Data
    union
    {
        DNS_OPT_DATA        OPT, Opt;

    } Data;
}
DNS_RECORD_OPTW, *PDNS_RECORD_OPTW;


typedef _Struct_size_bytes_(FIELD_OFFSET(struct _DnsRecordA, Data) + wDataLength) struct _DnsRecordA
{
    struct _DnsRecordA *    pNext;
    PSTR                    pName;
    WORD                    wType;
    WORD                    wDataLength; // Not referenced for DNS record types
                                     // defined above.
    union
    {
        DWORD               DW;     // flags as DWORD
        DNS_RECORD_FLAGS    S;      // flags as structure

    } Flags;

    DWORD               dwTtl;
    DWORD               dwReserved;

    //  Record Data

    union
    {
        DNS_A_DATA          A;
        DNS_SOA_DATAA       SOA, Soa;
        DNS_PTR_DATAA       PTR, Ptr,
                            NS, Ns,
                            CNAME, Cname,
                            DNAME, Dname,
                            MB, Mb,
                            MD, Md,
                            MF, Mf,
                            MG, Mg,
                            MR, Mr;
        DNS_MINFO_DATAA     MINFO, Minfo,
                            RP, Rp;
        DNS_MX_DATAA        MX, Mx,
                            AFSDB, Afsdb,
                            RT, Rt;
        DNS_TXT_DATAA       HINFO, Hinfo,
                            ISDN, Isdn,
                            TXT, Txt,
                            X25;
        DNS_NULL_DATA       Null;
        DNS_WKS_DATA        WKS, Wks;
        DNS_AAAA_DATA       AAAA;
        DNS_KEY_DATA        KEY, Key;
        DNS_SIG_DATAA       SIG, Sig;
        DNS_ATMA_DATA       ATMA, Atma;
        DNS_NXT_DATAA       NXT, Nxt;
        DNS_SRV_DATAA       SRV, Srv;
        DNS_NAPTR_DATAA     NAPTR, Naptr;
        DNS_OPT_DATA        OPT, Opt;
        DNS_DS_DATA         DS, Ds;
        DNS_RRSIG_DATAA     RRSIG, Rrsig;
        DNS_NSEC_DATAA      NSEC, Nsec;
        DNS_DNSKEY_DATA     DNSKEY, Dnskey;
        DNS_TKEY_DATAA      TKEY, Tkey;
        DNS_TSIG_DATAA      TSIG, Tsig;
        DNS_WINS_DATA       WINS, Wins;
        DNS_WINSR_DATAA     WINSR, WinsR, NBSTAT, Nbstat;
        DNS_DHCID_DATA      DHCID;
        DNS_NSEC3_DATA      NSEC3, Nsec3;
        DNS_NSEC3PARAM_DATA NSEC3PARAM, Nsec3Param;
        DNS_TLSA_DATA	    TLSA, Tlsa;
        DNS_UNKNOWN_DATA    UNKNOWN, Unknown;
        PBYTE               pDataPtr;

    } Data;
}
DNS_RECORDA, *PDNS_RECORDA;


typedef struct _DnsRecordOptA
{
    struct _DnsRecordA *    pNext;
    PSTR                    pName;
    WORD                    wType;
    WORD                    wDataLength; // Not referenced for DNS record types
                                     // defined above.
    union
    {
        DWORD               DW;     // flags as DWORD
        DNS_RECORD_FLAGS    S;      // flags as structure

    } Flags;

    DNS_HEADER_EXT          ExtHeader;      // TTL
    WORD                    wPayloadSize;   // dwReserved;
    WORD                    wReserved;

    //  Record Data

    union
    {
        DNS_OPT_DATA        OPT, Opt;

    } Data;
}
DNS_RECORD_OPTA, *PDNS_RECORD_OPTA;


#ifdef UNICODE
typedef DNS_RECORDW         DNS_RECORD, *PDNS_RECORD;
typedef DNS_RECORD_OPTW     DNS_RECORD_OPT, *PDNS_RECORD_OPT;
#else
typedef DNS_RECORDA         DNS_RECORD, *PDNS_RECORD;
typedef DNS_RECORD_OPTA     DNS_RECORD_OPT, *PDNS_RECORD_OPT;
#endif

//
//  Header or fixed size of DNS_RECORD
//

#define DNS_RECORD_FIXED_SIZE       FIELD_OFFSET( DNS_RECORD, Data )
#define SIZEOF_DNS_RECORD_HEADER    DNS_RECORD_FIXED_SIZE

#endif  // PRIVATE_DNS_RECORD


//
//  Resource record set building
//
//  pFirst points to first record in list.
//  pLast points to last record in list.
//

typedef struct _DnsRRSet
{
    PDNS_RECORD     pFirstRR;
    PDNS_RECORD     pLastRR;
}
DNS_RRSET, *PDNS_RRSET;


//
//  To init pFirst is NULL.
//  But pLast points at the location of the pFirst pointer -- essentially
//  treating the pFirst ptr as a DNS_RECORD.  (It is a DNS_RECORD with
//  only a pNext field, but that's the only part we use.)
//
//  Then when the first record is added to the list, the pNext field of
//  this dummy record (which corresponds to pFirst's value) is set to
//  point at the first record.  So pFirst then properly points at the
//  first record.
//
//  (This works only because pNext is the first field in a
//  DNS_RECORD structure and hence casting a PDNS_RECORD ptr to
//  PDNS_RECORD* and dereferencing yields its pNext field)
//
//  Use TERMINATE when have built RR set by grabbing records out of
//  existing set.   This makes sure that at the end, the last RR is
//  properly NULL terminated.
//

#define DNS_RRSET_INIT( rrset )                 \
        {                                       \
            PDNS_RRSET  _prrset = &(rrset);     \
            _prrset->pFirstRR = NULL;           \
            _prrset->pLastRR = (PDNS_RECORD) &_prrset->pFirstRR; \
        }

#define DNS_RRSET_ADD( rrset, pnewRR )          \
        {                                       \
            PDNS_RRSET  _prrset = &(rrset);     \
            PDNS_RECORD _prrnew = (pnewRR);     \
            _prrset->pLastRR->pNext = _prrnew;  \
            _prrset->pLastRR = _prrnew;         \
        }

#define DNS_RRSET_TERMINATE( rrset )            \
        {                                       \
            PDNS_RRSET  _prrset = &(rrset);     \
            _prrset->pLastRR->pNext = NULL;     \
        }



typedef
VOID
(WINAPI *DNS_PROXY_COMPLETION_ROUTINE) (
    _In_opt_ void *completionContext,
    _In_ DNS_STATUS status);


typedef enum DNS_PROXY_INFORMATION_TYPE {
                DNS_PROXY_INFORMATION_DIRECT,
                DNS_PROXY_INFORMATION_DEFAULT_SETTINGS,
                DNS_PROXY_INFORMATION_PROXY_NAME,
                DNS_PROXY_INFORMATION_DOES_NOT_EXIST
}   DNS_PROXY_INFORMATION_TYPE;

typedef struct DNS_PROXY_INFORMATION {
                _In_ ULONG version;  // Current version is 1
                _Out_ DNS_PROXY_INFORMATION_TYPE proxyInformationType;
                _Out_opt_ PWSTR proxyName;
} DNS_PROXY_INFORMATION;

//
//  Record set manipulation
//

//
//  Record Copy
//  Record copy functions also do conversion between character sets.
//
//  Note, it might be advisable to directly expose non-Ex copy
//  functions _W, _A for record and set, to avoid exposing the
//  conversion enum.
//

typedef enum _DNS_CHARSET
{
    DnsCharSetUnknown,
    DnsCharSetUnicode,
    DnsCharSetUtf8,
    DnsCharSetAnsi,
}
DNS_CHARSET;


PDNS_RECORD
WINAPI
DnsRecordCopyEx(
    _In_    PDNS_RECORD     pRecord,
    _In_    DNS_CHARSET     CharSetIn,
    _In_    DNS_CHARSET     CharSetOut
    );

PDNS_RECORD
WINAPI
DnsRecordSetCopyEx(
    _In_    PDNS_RECORD     pRecordSet,
    _In_    DNS_CHARSET     CharSetIn,
    _In_    DNS_CHARSET     CharSetOut
    );

#ifdef UNICODE
#define DnsRecordCopy(pRR)  \
        DnsRecordCopyEx( (pRR), DnsCharSetUnicode, DnsCharSetUnicode )
#define DnsRecordSetCopy(pRR)  \
        DnsRecordSetCopyEx( (pRR), DnsCharSetUnicode, DnsCharSetUnicode )
#else
#define DnsRecordCopy(pRR)  \
        DnsRecordCopyEx( (pRR), DnsCharSetAnsi, DnsCharSetAnsi )
#define DnsRecordSetCopy(pRR)  \
        DnsRecordSetCopyEx( (pRR), DnsCharSetAnsi, DnsCharSetAnsi )
#endif


//
//  Record Compare
//
//  Note:  these routines only compare records of the SAME character set.
//  (ANSI, unicode or UTF8).  Furthermore the routines assume the character
//  set is indicated within the record.  If compare of user created, rather
//  than DNS API created record lists is desired, then caller should use
//  DnsRecordCopy API and compare copies.
//

BOOL
WINAPI
DnsRecordCompare(
    _In_            PDNS_RECORD     pRecord1,
    _In_            PDNS_RECORD     pRecord2
    );

BOOL
WINAPI
DnsRecordSetCompare(
    _Inout_                 PDNS_RECORD     pRR1,
    _Inout_                 PDNS_RECORD     pRR2,
    _Outptr_opt_result_maybenull_     PDNS_RECORD *   ppDiff1,
    _Outptr_opt_result_maybenull_     PDNS_RECORD *   ppDiff2
    );

//
//  Detach next record set from record list
//

PDNS_RECORD
DnsRecordSetDetach(
    _Inout_         PDNS_RECORD     pRecordList
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
//  Free structures returned from dnsapi.dll
//
//  Currently supported free structures:
//      Flat -- flat structure, including those allocated by DnsQueryConfig()
//      RecordList -- deep record list free, including sub-fields of DNS_RECORD;
//          includes those returned by DnsQuery() or DnsRecordSetCopy()
//

typedef enum
{
    DnsFreeFlat = 0,
    DnsFreeRecordList,
    DnsFreeParsedMessageFields
}
DNS_FREE_TYPE;

VOID
WINAPI
DnsFree(
    _Pre_opt_valid_ _Frees_ptr_opt_    PVOID    pData,
    _In_        DNS_FREE_TYPE   FreeType
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
//  Backward compatibility with Win2K, do not use for XP+ applications
//
//  To free record lists, code
//      DnsFree( pRecordList, DnsFreeRecordList );
//

#define DnsFreeRecordListDeep   DnsFreeRecordList

#if(_WIN32_WINNT >= 0x0501)
#define DnsRecordListFree(p,t)  DnsFree(p,DnsFreeRecordList)
#else
VOID
WINAPI
DnsRecordListFree(
    _Inout_opt_ PDNS_RECORD     pRecordList,
    _In_        DNS_FREE_TYPE   FreeType
    );
#endif /* _WIN32_WINNT >= 0x0501 */


//
//  DNS Query API
//

//
//  Options for DnsQuery
//

#define DNS_QUERY_STANDARD                  0x00000000
#define DNS_QUERY_ACCEPT_TRUNCATED_RESPONSE 0x00000001
#define DNS_QUERY_USE_TCP_ONLY              0x00000002
#define DNS_QUERY_NO_RECURSION              0x00000004
#define DNS_QUERY_BYPASS_CACHE              0x00000008
#define DNS_QUERY_NO_WIRE_QUERY             0x00000010
#define DNS_QUERY_NO_LOCAL_NAME             0x00000020
#define DNS_QUERY_NO_HOSTS_FILE             0x00000040
#define DNS_QUERY_NO_NETBT                  0x00000080
#define DNS_QUERY_WIRE_ONLY                 0x00000100
#define DNS_QUERY_RETURN_MESSAGE            0x00000200
#define DNS_QUERY_MULTICAST_ONLY            0x00000400
#define DNS_QUERY_NO_MULTICAST              0x00000800
#define DNS_QUERY_TREAT_AS_FQDN             0x00001000
#define DNS_QUERY_ADDRCONFIG                0x00002000
#define DNS_QUERY_DUAL_ADDR                 0x00004000
#define DNS_QUERY_DONT_RESET_TTL_VALUES     0x00100000
#define DNS_QUERY_DISABLE_IDN_ENCODING      0x00200000
#define DNS_QUERY_APPEND_MULTILABEL         0x00800000
#define DNS_QUERY_DNSSEC_OK                 0x01000000
#define DNS_QUERY_DNSSEC_CHECKING_DISABLED  0x02000000
#define DNS_QUERY_RESERVED                  0xf0000000


//  Backward compatibility with Win2K
//  Do not use

#define DNS_QUERY_CACHE_ONLY                DNS_QUERY_NO_WIRE_QUERY



DNS_STATUS
WINAPI
DnsQuery_A(
    _In_                PCSTR           pszName,
    _In_                WORD            wType,
    _In_                DWORD           Options,
    _Inout_opt_         PVOID           pExtra,
    _Outptr_result_maybenull_     PDNS_RECORD *   ppQueryResults,
    _Outptr_opt_result_maybenull_ PVOID *         pReserved
    );

DNS_STATUS
WINAPI
DnsQuery_UTF8(
    _In_                PCSTR           pszName,
    _In_                WORD            wType,
    _In_                DWORD           Options,
    _Inout_opt_         PVOID           pExtra,
    _Outptr_result_maybenull_     PDNS_RECORD *   ppQueryResults,
    _Outptr_opt_result_maybenull_ PVOID *         pReserved
    );

DNS_STATUS
WINAPI
DnsQuery_W(
    _In_                PCWSTR          pszName,
    _In_                WORD            wType,
    _In_                DWORD           Options,
    _Inout_opt_         PVOID           pExtra,
    _Outptr_result_maybenull_     PDNS_RECORD *   ppQueryResults,
    _Outptr_opt_result_maybenull_ PVOID *         pReserved
    );

#ifdef UNICODE
#define DnsQuery DnsQuery_W
#else
#define DnsQuery DnsQuery_A
#endif

#if !defined ( USE_PRIVATE_DNS_ADDR ) || defined (MIDL_PASS)

//
//  DnsQueryEx
//

#define DNS_QUERY_RESULTS_VERSION1  0x1

typedef struct _DNS_QUERY_RESULT
{
    _In_        ULONG           Version;
    _Out_       DNS_STATUS      QueryStatus;
    _Out_       ULONG64         QueryOptions;
    _Out_       PDNS_RECORD     pQueryRecords;
    _Inout_opt_ PVOID           Reserved;
}
DNS_QUERY_RESULT, *PDNS_QUERY_RESULT;

typedef
VOID
WINAPI
DNS_QUERY_COMPLETION_ROUTINE(
    _In_        PVOID               pQueryContext,
    _Inout_     PDNS_QUERY_RESULT   pQueryResults
);

typedef DNS_QUERY_COMPLETION_ROUTINE *PDNS_QUERY_COMPLETION_ROUTINE;

#define DNS_QUERY_REQUEST_VERSION1  0x1

typedef struct _DNS_QUERY_REQUEST
{
    _In_        ULONG           Version;
    _In_opt_    PCWSTR          QueryName;
    _In_        WORD            QueryType;
    _In_        ULONG64         QueryOptions;
    _In_opt_    PDNS_ADDR_ARRAY pDnsServerList;
    _In_opt_    ULONG           InterfaceIndex;
    _In_opt_    PDNS_QUERY_COMPLETION_ROUTINE   pQueryCompletionCallback;
    _In_        PVOID           pQueryContext;
}
DNS_QUERY_REQUEST, *PDNS_QUERY_REQUEST;

typedef struct DECLSPEC_ALIGN(8) _DNS_QUERY_CANCEL
{
                CHAR            Reserved[32];
}
DNS_QUERY_CANCEL, *PDNS_QUERY_CANCEL;

DNS_STATUS
WINAPI
DnsQueryEx(
    _In_        PDNS_QUERY_REQUEST  pQueryRequest,
    _Inout_     PDNS_QUERY_RESULT   pQueryResults,
    _Inout_opt_ PDNS_QUERY_CANCEL   pCancelHandle
    );

DNS_STATUS
WINAPI
DnsCancelQuery(
    _In_        PDNS_QUERY_CANCEL    pCancelHandle
    );

#endif

//
//  DNS Update API
//
//      DnsAcquireContextHandle
//      DnsReleaseContextHandle
//      DnsModifyRecordsInSet
//      DnsReplaceRecordSet
//

//
//  Update flags
//

#define DNS_UPDATE_SECURITY_USE_DEFAULT     0x00000000
#define DNS_UPDATE_SECURITY_OFF             0x00000010
#define DNS_UPDATE_SECURITY_ON              0x00000020
#define DNS_UPDATE_SECURITY_ONLY            0x00000100
#define DNS_UPDATE_CACHE_SECURITY_CONTEXT   0x00000200
#define DNS_UPDATE_TEST_USE_LOCAL_SYS_ACCT  0x00000400
#define DNS_UPDATE_FORCE_SECURITY_NEGO      0x00000800
#define DNS_UPDATE_TRY_ALL_MASTER_SERVERS   0x00001000
#define DNS_UPDATE_SKIP_NO_UPDATE_ADAPTERS  0x00002000
#define DNS_UPDATE_REMOTE_SERVER            0x00004000
#define DNS_UPDATE_RESERVED                 0xffff0000


//
//  Note:  pCredentials paramater is currently respectively
//  PSEC_WINNT_AUTH_IDENTITY_W or PSEC_WINNT_AUTH_IDENTITY_A.
//  Using PVOID to obviate the need for including rpcdce.h
//  in order to include this file and to leave open the
//  possibility of alternative credential specifications in
//  the future.
//

DNS_STATUS
WINAPI
DnsAcquireContextHandle_W(
    _In_            DWORD           CredentialFlags,
    _In_opt_        PVOID           Credentials,
    _Outptr_     PHANDLE         pContext
    );

DNS_STATUS
WINAPI
DnsAcquireContextHandle_A(
    _In_            DWORD           CredentialFlags,
    _In_opt_        PVOID           Credentials,
    _Outptr_     PHANDLE         pContext
    );

#ifdef UNICODE
#define DnsAcquireContextHandle DnsAcquireContextHandle_W
#else
#define DnsAcquireContextHandle DnsAcquireContextHandle_A
#endif

VOID
WINAPI
DnsReleaseContextHandle(
    _In_        HANDLE          hContext
    );

//
//  Dynamic Update API
//

DNS_STATUS
WINAPI
DnsModifyRecordsInSet_W(
    _In_opt_        PDNS_RECORD     pAddRecords,
    _In_opt_        PDNS_RECORD     pDeleteRecords,
    _In_            DWORD           Options,
    _In_opt_        HANDLE          hCredentials,
    _Inout_opt_     PVOID           pExtraList,
    _Inout_opt_     PVOID           pReserved
    );

DNS_STATUS
WINAPI
DnsModifyRecordsInSet_A(
    _In_opt_        PDNS_RECORD     pAddRecords,
    _In_opt_        PDNS_RECORD     pDeleteRecords,
    _In_            DWORD           Options,
    _In_opt_        HANDLE          hCredentials,
    _Inout_opt_     PVOID           pExtraList,
    _Inout_opt_     PVOID           pReserved
    );

DNS_STATUS
WINAPI
DnsModifyRecordsInSet_UTF8(
    _In_opt_        PDNS_RECORD     pAddRecords,
    _In_opt_        PDNS_RECORD     pDeleteRecords,
    _In_            DWORD           Options,
    _In_opt_        HANDLE          hCredentials,
    _Inout_opt_     PVOID           pExtraList,
    _Inout_opt_     PVOID           pReserved
    );

#ifdef UNICODE
#define DnsModifyRecordsInSet  DnsModifyRecordsInSet_W
#else
#define DnsModifyRecordsInSet  DnsModifyRecordsInSet_A
#endif


DNS_STATUS
WINAPI
DnsReplaceRecordSetW(
    _In_            PDNS_RECORD     pReplaceSet,
    _In_            DWORD           Options,
    _In_opt_        HANDLE          hContext,
    _Inout_opt_     PVOID           pExtraInfo,
    _Inout_opt_     PVOID           pReserved
    );

DNS_STATUS
WINAPI
DnsReplaceRecordSetA(
    _In_            PDNS_RECORD     pReplaceSet,
    _In_            DWORD           Options,
    _In_opt_        HANDLE          hContext,
    _Inout_opt_     PVOID           pExtraInfo,
    _Inout_opt_     PVOID           pReserved
    );

DNS_STATUS
WINAPI
DnsReplaceRecordSetUTF8(
    _In_            PDNS_RECORD     pReplaceSet,
    _In_            DWORD           Options,
    _In_opt_        HANDLE          hContext,
    _Inout_opt_     PVOID           pExtraInfo,
    _Inout_opt_     PVOID           pReserved
    );

#ifdef UNICODE
#define DnsReplaceRecordSet  DnsReplaceRecordSetW
#else
#define DnsReplaceRecordSet  DnsReplaceRecordSetA
#endif



//
//  DNS name validation
//

typedef enum _DNS_NAME_FORMAT
{
    DnsNameDomain,
    DnsNameDomainLabel,
    DnsNameHostnameFull,
    DnsNameHostnameLabel,
    DnsNameWildcard,
    DnsNameSrvRecord,
    DnsNameValidateTld
}
DNS_NAME_FORMAT;


DNS_STATUS
DnsValidateName_W(
    _In_    PCWSTR          pszName,
    _In_    DNS_NAME_FORMAT Format
    );

DNS_STATUS
DnsValidateName_A(
    _In_    PCSTR           pszName,
    _In_    DNS_NAME_FORMAT Format
    );

DNS_STATUS
DnsValidateName_UTF8(
    _In_    PCSTR           pszName,
    _In_    DNS_NAME_FORMAT Format
    );

#ifdef UNICODE
#define DnsValidateName(p,f)    DnsValidateName_W( (p), (f) )
#else
#define DnsValidateName(p,f)    DnsValidateName_A( (p), (f) )
#endif

//
// DNS server validation
//

// DNS server validation error codes
#define DNS_VALSVR_ERROR_INVALID_ADDR               0x01
#define DNS_VALSVR_ERROR_INVALID_NAME               0x02
#define DNS_VALSVR_ERROR_UNREACHABLE                0x03
#define DNS_VALSVR_ERROR_NO_RESPONSE                0x04
#define DNS_VALSVR_ERROR_NO_AUTH                    0x05
#define DNS_VALSVR_ERROR_REFUSED                    0x06

#define DNS_VALSVR_ERROR_NO_TCP                     0x10
#define DNS_VALSVR_ERROR_UNKNOWN                    0xFF

// Winsock2.h must be included before windns.h to use the validate server function
#ifdef _WS2DEF_

DNS_STATUS
DnsValidateServerStatus(
    _In_        PSOCKADDR   server,
    _In_opt_    PCWSTR      queryName,
    _Out_       PDWORD      serverStatus
    );

#endif

//
//  DNS name comparison
//

BOOL
WINAPI
DnsNameCompare_A(
    _In_    PCSTR           pName1,
    _In_    PCSTR           pName2
    );

BOOL
WINAPI
DnsNameCompare_W(
    _In_    PCWSTR          pName1,
    _In_    PCWSTR          pName2
    );

#ifdef UNICODE
#define DnsNameCompare(n1,n2)   DnsNameCompare_W( (n1),(n2) )
#else
#define DnsNameCompare(n1,n2)   DnsNameCompare_A( (n1),(n2) )
#endif



//
//  DNS message "roll-your-own" routines
//

typedef struct _DNS_MESSAGE_BUFFER
{
    DNS_HEADER  MessageHead;
    CHAR        MessageBody[1];
}
DNS_MESSAGE_BUFFER, *PDNS_MESSAGE_BUFFER;

BOOL
WINAPI
DnsWriteQuestionToBuffer_W(
    _Inout_     PDNS_MESSAGE_BUFFER pDnsBuffer,
    _Inout_     PDWORD              pdwBufferSize,
    _In_        PCWSTR              pszName,
    _In_        WORD                wType,
    _In_        WORD                Xid,
    _In_        BOOL                fRecursionDesired
    );

BOOL
WINAPI
DnsWriteQuestionToBuffer_UTF8(
    _Inout_     PDNS_MESSAGE_BUFFER pDnsBuffer,
    _Inout_     PDWORD              pdwBufferSize,
    _In_        PCSTR               pszName,
    _In_        WORD                wType,
    _In_        WORD                Xid,
    _In_        BOOL                fRecursionDesired
    );

DNS_STATUS
WINAPI
DnsExtractRecordsFromMessage_W(
    _In_            PDNS_MESSAGE_BUFFER pDnsBuffer,
    _In_            WORD                wMessageLength,
    _Outptr_     PDNS_RECORD *       ppRecord
    );

DNS_STATUS
WINAPI
DnsExtractRecordsFromMessage_UTF8(
    _In_            PDNS_MESSAGE_BUFFER pDnsBuffer,
    _In_            WORD                wMessageLength,
    _Outptr_     PDNS_RECORD *       ppRecord
    );



//
//  DNS name resolution policy table
//

DWORD
WINAPI
DnsGetProxyInformation(
    _In_        PCWSTR                          hostName,
    _Inout_     DNS_PROXY_INFORMATION *         proxyInformation,
    _Inout_opt_ DNS_PROXY_INFORMATION *         defaultProxyInformation,
    _In_opt_    DNS_PROXY_COMPLETION_ROUTINE    completionRoutine,
    _In_opt_    void *                          completionContext
    );

VOID
WINAPI
DnsFreeProxyName(
    _Frees_ptr_opt_ PWSTR   proxyName
    );

//
//  Connections Proxy configuration APIs
//

//
// Connection Proxy APIs.
//

#define DNS_CONNECTION_NAME_MAX_LENGTH                      64
#define DNS_CONNECTION_PROXY_INFO_CURRENT_VERSION           1
#define DNS_CONNECTION_PROXY_INFO_SERVER_MAX_LENGTH         256
#define DNS_CONNECTION_PROXY_INFO_FRIENDLY_NAME_MAX_LENGTH  64
#define DNS_CONNECTION_PROXY_INFO_USERNAME_MAX_LENGTH       128
#define DNS_CONNECTION_PROXY_INFO_PASSWORD_MAX_LENGTH       128
#define DNS_CONNECTION_PROXY_INFO_EXCEPTION_MAX_LENGTH      1024
#define DNS_CONNECTION_PROXY_INFO_EXTRA_INFO_MAX_LENGTH     1024

//
// Proxy type definition.
//

typedef enum _DNS_CONNECTION_PROXY_TYPE
{
    DNS_CONNECTION_PROXY_TYPE_NULL      = 0,
    DNS_CONNECTION_PROXY_TYPE_HTTP      = 1,
    DNS_CONNECTION_PROXY_TYPE_WAP       = 2,
    DNS_CONNECTION_PROXY_TYPE_SOCKS4    = 4,
    DNS_CONNECTION_PROXY_TYPE_SOCKS5    = 5
} DNS_CONNECTION_PROXY_TYPE;

//
// This enum indicate whether the DNS_CONNECTION_PROXY_INFO data structure
// contains the 'CONFIG' information or the 'SCRIPT' information.
//

typedef enum _DNS_CONNECTION_PROXY_INFO_SWITCH
{
    DNS_CONNECTION_PROXY_INFO_SWITCH_CONFIG = 0,
    DNS_CONNECTION_PROXY_INFO_SWITCH_SCRIPT,
    DNS_CONNECTION_PROXY_INFO_SWITCH_WPAD
} DNS_CONNECTION_PROXY_INFO_SWITCH;

//
// These flags can be ORed to form the 'Flags' field of DNS_CONNECTION_PROXY_INFO.
//

#define DNS_CONNECTION_PROXY_INFO_FLAG_DISABLED     0x1
#define DNS_CONNECTION_PROXY_INFO_FLAG_BYPASSLOCAL  0x2

#pragma warning(push)
#pragma warning(disable: 4201)

typedef struct _DNS_CONNECTION_PROXY_INFO
{
    DWORD Version;
    WCHAR *pwszFriendlyName;
    DWORD Flags;
    DNS_CONNECTION_PROXY_INFO_SWITCH Switch;
    union
    {
        struct _DNS_CONNECTION_PROXY_INFO_CONFIG
        {
            WCHAR *pwszServer;
            WCHAR *pwszUsername;
            WCHAR *pwszPassword;
            WCHAR *pwszException;
            WCHAR *pwszExtraInfo;
            WORD Port;
        } Config;

        struct _DNS_CONNECTION_PROXY_INFO_SCRIPT
        {
            WCHAR *pwszScript;
            WCHAR *pwszUsername;
            WCHAR *pwszPassword;
        } Script;
    };
} DNS_CONNECTION_PROXY_INFO, *PDNS_CONNECTION_PROXY_INFO;

#pragma warning(pop)

typedef struct _DNS_CONNECTION_PROXY_INFO_EX
{
    DNS_CONNECTION_PROXY_INFO ProxyInfo;
    DWORD dwInterfaceIndex;
    WCHAR *pwszConnectionName;
    BOOL fDirectConfiguration;
    HANDLE hConnection;
} DNS_CONNECTION_PROXY_INFO_EX, *PDNS_CONNECTION_PROXY_INFO_EX;

typedef struct _DNS_CONNECTION_PROXY_ELEMENT
{
    DNS_CONNECTION_PROXY_TYPE Type;
    DNS_CONNECTION_PROXY_INFO Info;
} DNS_CONNECTION_PROXY_ELEMENT;

typedef struct _DNS_CONNECTION_PROXY_LIST
{
    DWORD cProxies;
    DNS_CONNECTION_PROXY_ELEMENT *pProxies;
} DNS_CONNECTION_PROXY_LIST;

typedef struct _DNS_CONNECTION_NAME
{
    WCHAR wszName[DNS_CONNECTION_NAME_MAX_LENGTH + 1];
} DNS_CONNECTION_NAME;

typedef struct _DNS_CONNECTION_NAME_LIST
{
    DWORD cNames;
    DNS_CONNECTION_NAME *pNames;
} DNS_CONNECTION_NAME_LIST;

DWORD
DnsConnectionGetProxyInfoForHostUrl(
    _In_z_ PCWSTR pwszHostUrl,
    _In_reads_opt_(dwSelectionContextLength) BYTE *pSelectionContext,
    _In_ DWORD dwSelectionContextLength,
    _In_ DWORD dwExplicitInterfaceIndex,
    _Out_ DNS_CONNECTION_PROXY_INFO_EX *pProxyInfoEx
);

VOID
DnsConnectionFreeProxyInfoEx(
    _Inout_ DNS_CONNECTION_PROXY_INFO_EX *pProxyInfoEx
);

DWORD
DnsConnectionGetProxyInfo(
    _In_z_ PCWSTR pwszConnectionName,
    _In_ DNS_CONNECTION_PROXY_TYPE Type,
    _Out_ DNS_CONNECTION_PROXY_INFO *pProxyInfo
);

VOID
DnsConnectionFreeProxyInfo(
    _Inout_ DNS_CONNECTION_PROXY_INFO *pProxyInfo
);

DWORD
DnsConnectionSetProxyInfo(
    _In_z_ PCWSTR pwszConnectionName,
    _In_ DNS_CONNECTION_PROXY_TYPE Type,
    _In_ const DNS_CONNECTION_PROXY_INFO *pProxyInfo
);

DWORD
DnsConnectionDeleteProxyInfo(
    _In_z_ PCWSTR pwszConnectionName,
    _In_  DNS_CONNECTION_PROXY_TYPE Type
);

DWORD
DnsConnectionGetProxyList(
    _In_z_ PCWSTR pwszConnectionName,
    _Out_ DNS_CONNECTION_PROXY_LIST *pProxyList
);

VOID
DnsConnectionFreeProxyList(
    _Inout_ DNS_CONNECTION_PROXY_LIST *pProxyList
);

DWORD
DnsConnectionGetNameList(
    _Out_ DNS_CONNECTION_NAME_LIST *pNameList
);

VOID
DnsConnectionFreeNameList(
    _Inout_ DNS_CONNECTION_NAME_LIST *pNameList
);

//
// Connection <-> Active Interface Index mapping APIs
//

typedef struct _DNS_CONNECTION_IFINDEX_ENTRY
{
    PCWSTR pwszConnectionName;
    DWORD dwIfIndex;
} DNS_CONNECTION_IFINDEX_ENTRY;

typedef struct _DNS_CONNECTION_IFINDEX_LIST
{
    DNS_CONNECTION_IFINDEX_ENTRY *pConnectionIfIndexEntries;
    DWORD nEntries;
}  DNS_CONNECTION_IFINDEX_LIST;

DWORD
DnsConnectionUpdateIfIndexTable(
    _In_ DNS_CONNECTION_IFINDEX_LIST *pConnectionIfIndexEntries
);

//
// Connection Policy Configuration APIs
//

#define DNS_CONNECTION_POLICY_ENTRY_ONDEMAND 0x00000001

typedef struct _DNS_CONNECTION_POLICY_ENTRY
{
    PCWSTR pwszHost;
    PCWSTR pwszAppId;
    DWORD cbAppSid;
    PBYTE pbAppSid;
    DWORD nConnections;
    PCWSTR *ppwszConnections;
    DWORD dwPolicyEntryFlags;
} DNS_CONNECTION_POLICY_ENTRY, *PDNS_CONNECTION_POLICY_ENTRY;

typedef struct _DNS_CONNECTION_POLICY_ENTRY_LIST
{
#ifdef MIDL_PASS
    [size_is(nEntries)] DNS_CONNECTION_POLICY_ENTRY *pPolicyEntries;
#else
    DNS_CONNECTION_POLICY_ENTRY *pPolicyEntries;
#endif
    DWORD nEntries;
} DNS_CONNECTION_POLICY_ENTRY_LIST;

typedef enum
{
    TAG_DNS_CONNECTION_POLICY_TAG_DEFAULT = 0,
    TAG_DNS_CONNECTION_POLICY_TAG_CONNECTION_MANAGER,
    TAG_DNS_CONNECTION_POLICY_TAG_WWWPT
} DNS_CONNECTION_POLICY_TAG;

DWORD
DnsConnectionSetPolicyEntries(
    _In_ DNS_CONNECTION_POLICY_TAG PolicyEntryTag,
    _In_ DNS_CONNECTION_POLICY_ENTRY_LIST *pPolicyEntryList
);

DWORD
DnsConnectionDeletePolicyEntries(
    _In_ DNS_CONNECTION_POLICY_TAG PolicyEntryTag
);

#ifdef __midl
typedef[string] wchar_t *DNSSD_RPC_STRING;
#endif

typedef struct _DNS_SERVICE_INSTANCE
{
#ifdef __midl
    DNSSD_RPC_STRING    pszInstanceName;
#else
    LPWSTR              pszInstanceName;
#endif
#ifdef __midl
    DNSSD_RPC_STRING    pszHostName;
#else
    LPWSTR              pszHostName;
#endif

    IP4_ADDRESS *ip4Address;
    IP6_ADDRESS *ip6Address;

    WORD wPort;
    WORD wPriority;
    WORD wWeight;

    // Property list
    DWORD dwPropertyCount;
#ifdef __midl
    [size_is(dwPropertyCount)] DNSSD_RPC_STRING *keys;
    [size_is(dwPropertyCount)] DNSSD_RPC_STRING *values;
#else
    PWSTR *keys;
    PWSTR *values;
#endif

    DWORD dwInterfaceIndex;
} DNS_SERVICE_INSTANCE, *PDNS_SERVICE_INSTANCE;

#ifndef __midl

PDNS_SERVICE_INSTANCE
DnsServiceConstructInstance(
    _In_ PCWSTR pServiceName,
    _In_ PCWSTR pHostName,
    _In_opt_ PIP4_ADDRESS pIp4,
    _In_opt_ PIP6_ADDRESS pIp6,
    _In_ WORD wPort,
    _In_ WORD wPriority,
    _In_ WORD wWeight,
    _In_ DWORD dwPropertiesCount,
    _In_reads_(dwPropertiesCount) PCWSTR *keys,
    _In_reads_(dwPropertiesCount) PCWSTR *values
    );

PDNS_SERVICE_INSTANCE
DnsServiceCopyInstance(
    _In_ PDNS_SERVICE_INSTANCE pOrig
    );

VOID
DnsServiceFreeInstance(
    _In_ PDNS_SERVICE_INSTANCE pInstance
    );

//
// Cancellation mechanism
//

typedef struct _DNS_SERVICE_CANCEL{
    PVOID reserved;
} DNS_SERVICE_CANCEL, *PDNS_SERVICE_CANCEL;

//
// Browse
//

typedef
VOID
WINAPI
DNS_SERVICE_BROWSE_CALLBACK(
    _In_    DWORD Status,
    _In_    PVOID pQueryContext,
    _In_    PDNS_RECORD pDnsRecord
    );

typedef DNS_SERVICE_BROWSE_CALLBACK *PDNS_SERVICE_BROWSE_CALLBACK;

#if defined(USE_PRIVATE_DNS_ADDR)

#define DNS_QUERY_RESULTS_VERSION1  0x1

typedef struct _DNS_QUERY_RESULT
{
    _In_        ULONG           Version;
    _Out_       DNS_STATUS      QueryStatus;
    _Out_       ULONG64         QueryOptions;
    _Out_       PDNS_RECORD     pQueryRecords;
    _Inout_opt_ PVOID           Reserved;
}
DNS_QUERY_RESULT, *PDNS_QUERY_RESULT;

typedef
VOID
WINAPI
DNS_QUERY_COMPLETION_ROUTINE(
    _In_        PVOID               pQueryContext,
    _Inout_     PDNS_QUERY_RESULT   pQueryResults
);

typedef DNS_QUERY_COMPLETION_ROUTINE *PDNS_QUERY_COMPLETION_ROUTINE;

#endif

#pragma warning(push)
#pragma warning(disable: 4201)

//
// For DNS_QUERY_REQUEST_VERSION2 Version,
// pBrowseCallback needs to be a DNS_QUERY_COMPLETION_ROUTINE callback
//
typedef struct _DNS_SERVICE_BROWSE_REQUEST
{
    ULONG   Version;
    ULONG   InterfaceIndex;
    PCWSTR  QueryName;
    union
    {
        PDNS_SERVICE_BROWSE_CALLBACK pBrowseCallback;
        DNS_QUERY_COMPLETION_ROUTINE *pBrowseCallbackV2;
    };
    PVOID   pQueryContext;
} DNS_SERVICE_BROWSE_REQUEST, *PDNS_SERVICE_BROWSE_REQUEST;

#pragma warning(pop)

DNS_STATUS
WINAPI
DnsServiceBrowse(
    _In_    PDNS_SERVICE_BROWSE_REQUEST    pRequest,
    _Inout_ PDNS_SERVICE_CANCEL            pCancel
    );

DNS_STATUS
WINAPI
DnsServiceBrowseCancel(
    _In_ PDNS_SERVICE_CANCEL pCancelHandle
    );

//
// Resolve
//

typedef
VOID
WINAPI
DNS_SERVICE_RESOLVE_COMPLETE(
    _In_ DWORD Status,
    _In_ PVOID pQueryContext,
    _In_ PDNS_SERVICE_INSTANCE pInstance
    );

typedef DNS_SERVICE_RESOLVE_COMPLETE *PDNS_SERVICE_RESOLVE_COMPLETE;

typedef struct _DNS_SERVICE_RESOLVE_REQUEST{
    ULONG   Version;
    ULONG   InterfaceIndex;
    PWSTR   QueryName;
    PDNS_SERVICE_RESOLVE_COMPLETE pResolveCompletionCallback;
    PVOID pQueryContext;
} DNS_SERVICE_RESOLVE_REQUEST, *PDNS_SERVICE_RESOLVE_REQUEST;

DNS_STATUS
WINAPI
DnsServiceResolve(
    _In_    PDNS_SERVICE_RESOLVE_REQUEST    pRequest,
    _Inout_ PDNS_SERVICE_CANCEL             pCancel
    );

DNS_STATUS
WINAPI
DnsServiceResolveCancel(
    _In_ PDNS_SERVICE_CANCEL pCancelHandle
    );

//
// Register
//

typedef
VOID
WINAPI
DNS_SERVICE_REGISTER_COMPLETE(
    _In_    DWORD Status,
    _In_    PVOID pQueryContext,
    _In_   PDNS_SERVICE_INSTANCE pInstance
    );

typedef DNS_SERVICE_REGISTER_COMPLETE *PDNS_SERVICE_REGISTER_COMPLETE;

typedef struct _DNS_SERVICE_REGISTER_REQUEST{
    ULONG Version;
    ULONG   InterfaceIndex;
    PDNS_SERVICE_INSTANCE pServiceInstance;
    PDNS_SERVICE_REGISTER_COMPLETE pRegisterCompletionCallback;
    PVOID pQueryContext;
    HANDLE hCredentials;
    BOOL unicastEnabled;
} DNS_SERVICE_REGISTER_REQUEST, *PDNS_SERVICE_REGISTER_REQUEST;

DWORD
DnsServiceRegister(
    _In_    PDNS_SERVICE_REGISTER_REQUEST   pRequest,
    _Inout_opt_ PDNS_SERVICE_CANCEL             pCancel
    );

DWORD
DnsServiceDeRegister(
    _In_    PDNS_SERVICE_REGISTER_REQUEST   pRequest,
    _Inout_opt_ PDNS_SERVICE_CANCEL             pCancel
    );

DWORD
DnsServiceRegisterCancel(
    _In_ PDNS_SERVICE_CANCEL pCancelHandle
    );

#endif  // __midl

typedef struct _MDNS_QUERY_HANDLE
{
    WCHAR nameBuf[DNS_MAX_NAME_BUFFER_LENGTH];
    WORD  wType;

    // Internal notification bookkeeping, do not edit
    PVOID pSubscription;
    PVOID pWnfCallbackParams;
    ULONG stateNameData[2];
} MDNS_QUERY_HANDLE, *PMDNS_QUERY_HANDLE;

typedef VOID WINAPI MDNS_QUERY_CALLBACK(
    _In_    PVOID pQueryContext,
    _Inout_ PMDNS_QUERY_HANDLE pQueryHandle,
    _Inout_ PDNS_QUERY_RESULT pQueryResults
    );

typedef MDNS_QUERY_CALLBACK *PMDNS_QUERY_CALLBACK;

typedef struct _MDNS_QUERY_REQUEST
{
    ULONG                   Version;
    ULONG                   ulRefCount;      // Refcount for async query
    PCWSTR                  Query;
    WORD                    QueryType;
    ULONG64                 QueryOptions;
    ULONG                   InterfaceIndex;
    PMDNS_QUERY_CALLBACK    pQueryCallback;
    PVOID                   pQueryContext;
    BOOL                    fAnswerReceived; // Reserved
    ULONG                   ulResendCount;   // Reserved
} MDNS_QUERY_REQUEST, *PMDNS_QUERY_REQUEST;

DNS_STATUS WINAPI DnsStartMulticastQuery(
    _In_        PMDNS_QUERY_REQUEST pQueryRequest,
    _Inout_     PMDNS_QUERY_HANDLE pHandle
    );

DNS_STATUS WINAPI DnsStopMulticastQuery(
    _Inout_     PMDNS_QUERY_HANDLE pHandle
    );

//
// End of mDNS definitions
//

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#endif // _WINDNS_INCLUDED_
