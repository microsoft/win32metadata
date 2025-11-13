/**
 * @file
 * Functions required to startup and cleanup AllJoyn.
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
#ifndef _ALLJOYN_C_INIT_H
#define _ALLJOYN_C_INIT_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/Status.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This must be called prior to instantiating or using any AllJoyn
 * functionality.
 *
 * alljoyn_shutdown must be called for each invocation of alljoyn_init.
 *
 * @return
 *  - #ER_OK on success
 *  - error code indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_init(void);

/**
 * Call this to release any resources acquired in alljoyn_init().  No AllJoyn
 * functionality may be used after calling this.
 *
 * alljoyn_shutdown must be called for each invocation of alljoyn_init.
 * alljoyn_shutdown must not be called without a prior alljoyn_init call.
 *
 * @return
 *  - #ER_OK on success
 *  - error code indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_shutdown(void);

/**
 * This must be called before using any AllJoyn router functionality.
 *
 * For an application that is a routing node (either standalone or bundled), the
 * complete initialization sequence is:
 * @code
 * alljoyn_init();
 * alljoyn_routerinit();
 * @endcode
 *
 * alljoyn_routershutdown must be called for each invocation of alljoyn_routerinit.
 *
 * @return
 *  - #ER_OK on success
 *  - error code indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_routerinit(void);

/**
 * A variant of alljoyn_routerinit which allows providing a custom configuration.
 *
 * @see alljoyn_routerinit
 *
 * alljoyn_routerinit() initializes the routing node (bundled or standalone) with a default,
 * hard-coded configuration. For a standalone routing node, the default configuration
 * can be overridden by using an XML configuration file. For a bundled routing node,
 * custom configuration, defined as an XML string, can be provided via alljoyn_routerinitwithconfig().
 * In that case, alljoyn_routerinitwithconfig() should be called instead of alljoyn_routerinit().
 * For example:
 * @code
 * static const char myConfig[] =
 *     "<busconfig>"
 *     "  <type>alljoyn_bundled</type>"
 *     "  <listen>tcp:iface=*,port=0</listen>"
 *     "  <listen>udp:iface=*,port=0</listen>"
 *     "  <limit name=\"auth_timeout\">20000</limit>"
 *     "  <limit name=\"max_incomplete_connections\">48</limit>"
 *     "  <limit name=\"max_completed_connections\">64</limit>"
 *     "  <limit name=\"max_remote_clients_tcp\">48</limit>"
 *     "  <limit name=\"max_remote_clients_udp\">48</limit>"
 *     "  <limit name=\"udp_link_timeout\">60000</limit>"
 *     "  <limit name=\"udp_keepalive_retries\">6</limit>"
 *     "  <property name=\"router_power_source\">Battery powered and chargeable</property>"
 *     "  <property name=\"router_mobility\">Intermediate mobility</property>"
 *     "  <property name=\"router_availability\">3-6 hr</property>"
 *     "  <property name=\"router_node_connection\">Wireless</property>"
 *     "</busconfig>";
 *
 * alljoyn_init();
 * alljoyn_routerinitwithconfig(myConfig);
 * @endcode
 *
 * @see https://allseenalliance.org/framework/documentation/learn/core/rn_config for a description
 * of the available configuration elements.
 *
 * alljoyn_routershutdown() must be called for each invocation of alljoyn_routerinitwithconfig().
 * If the provided XML is invalid and does not parse, the routing node will fall back to
 * the default configuration.
 * alljoyn_routerinitwithconfig() can be used only with bundled routing nodes. In order to have
 * custom configuration on a standalone router (router daemon), please create an XML file with
 * the configuration and use the "--config-file" option.
 *
 * @return
 *  - #ER_OK on success
 *  - error code indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_routerinitwithconfig(AJ_PCSTR configXml);

/**
 * Call this to release any resources acquired in alljoyn_routerinit()
 * or alljoyn_routerinitwithconfig().
 *
 * For an application that is a routing node (either standalone or bundled), the
 * complete shutdown sequence is:
 * @code
 * alljoyn_routershutdown();
 * alljoyn_shutdown();
 * @endcode
 *
 * alljoyn_routershutdown must be called for each invocation of alljoyn_routerinit.
 * alljoyn_routershutdown must not be called without a prior alljoyn_routerinit call.
 *
 * @return
 *  - #ER_OK on success
 *  - error code indicating failure otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_routershutdown(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
