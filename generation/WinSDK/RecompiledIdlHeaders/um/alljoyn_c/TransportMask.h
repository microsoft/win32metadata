/**
 * @file
 * Transport type definitions
 */

/******************************************************************************
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/
#ifndef _ALLJOYN_C_TRANPORTMASK_H
#define _ALLJOYN_C_TRANPORTMASK_H

#include <alljoyn_c/AjAPI.h>

/** Bitmask of all transport types */
typedef uint16_t alljoyn_transportmask;

#define ALLJOYN_TRANSPORT_NONE         (alljoyn_transportmask)0x0000   /**< no transports */
#define ALLJOYN_TRANSPORT_LOCAL        (alljoyn_transportmask)0x0001   /**< Local (same device) transport */
#define ALLJOYN_TRANSPORT_TCP          (alljoyn_transportmask)0x0004   /**< TCP/IP transport */
#define ALLJOYN_TRANSPORT_UDP          (alljoyn_transportmask)0x0100   /**< UDP/IP transport */
#define ALLJOYN_TRANSPORT_EXPERIMENTAL (alljoyn_transportmask)0x8000   /**< Placeholder for expermimental transports */

#define ALLJOYN_TRANSPORT_IP           (ALLJOYN_TRANSPORT_TCP | ALLJOYN_TRANSPORT_UDP)  /**< Any IP-based transport */
#define ALLJOYN_TRANSPORT_ANY          (ALLJOYN_TRANSPORT_LOCAL | ALLJOYN_TRANSPORT_IP) /**< ANY non-experimental transport */

#define ALLJOYN_TRANSPORT_BLUETOOTH (alljoyn_transportmask)(attempted_use_of_deprecated_definition = 0x0002)   /**< Bluetooth transport */
#define ALLJOYN_TRANSPORT_WLAN      (alljoyn_transportmask)(attempted_use_of_deprecated_definition = 0x0004)   /**< Wireless local-area network transport */
#define ALLJOYN_TRANSPORT_WWAN      (alljoyn_transportmask)(attempted_use_of_deprecated_definition = 0x0008)   /**< Wireless wide-area network transport */
#define ALLJOYN_TRANSPORT_LAN       (alljoyn_transportmask)(attempted_use_of_deprecated_definition = 0x0010)   /**< Wired local-area network transport */
#define ALLJOYN_TRANSPORT_PROXIMITY (alljoyn_transportmask)(attempted_use_of_deprecated_definition = 0x0040)   /**< Transport using WinRT Proximity Framework */
#define ALLJOYN_TRANSPORT_WFD       (alljoyn_transportmask)(attempted_use_of_deprecated_definition = 0x0080)   /**< Transport using Wi-Fi Direct transport */

#endif
