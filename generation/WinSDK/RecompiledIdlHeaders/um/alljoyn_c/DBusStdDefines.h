#ifndef _ALLJOYN_DBUSSTD_DEFINES_H
#define _ALLJOYN_DBUSSTD_DEFINES_H

/**
 * @file
 * This file provides \#define constant definitions for parameters of standard DBus methods.
 *
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


/**
 * @name DBus RequestName input params
 * org.freedesktop.DBus.RequestName input params (see DBus spec)
 */
// @{
#define DBUS_NAME_FLAG_ALLOW_REPLACEMENT 0x01u     /**< RequestName input flag: Allow others to take ownership of this name */
#define DBUS_NAME_FLAG_REPLACE_EXISTING  0x02u     /**< RequestName input flag: Attempt to take ownership of name if already taken */
#define DBUS_NAME_FLAG_DO_NOT_QUEUE      0x04u     /**< RequestName input flag: Fail if name cannot be immediately obtained */
// @}
/**
 * @name DBus RequestName return values
 * org.freedesktop.DBUs.RequestName return values (see DBus spec)
 */
// @{
#define DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER   1u   /**< RequestName reply: Name was successfully obtained */
#define DBUS_REQUEST_NAME_REPLY_IN_QUEUE        2u   /**< RequestName reply: Name is already owned, request for name has been queued */
#define DBUS_REQUEST_NAME_REPLY_EXISTS          3u   /**< RequestName reply: Name is already owned and DO_NOT_QUEUE was specified in request */
#define DBUS_REQUEST_NAME_REPLY_ALREADY_OWNER   4u   /**< RequestName reply: Name is already owned by this endpoint */
// @}

/**
 * @name DBus ReleaaseName return values
 * org.freedesktop.DBus.ReleaseName return values (see DBus spec)
 */
// @{
#define DBUS_RELEASE_NAME_REPLY_RELEASED      1u     /**< ReleaseName reply: Name was released */
#define DBUS_RELEASE_NAME_REPLY_NON_EXISTENT  2u     /**< ReleaseName reply: Name does not exist */
#define DBUS_RELEASE_NAME_REPLY_NOT_OWNER     3u     /**< ReleaseName reply: Request to release name that is not owned by this endpoint */
// @}
/**
 * @name DBus StartServiceByName return values
 * org.freedesktop.DBus.StartService return values (see DBus spec)
 */
// @{
#define DBUS_START_REPLY_SUCCESS          1u         /**< StartServiceByName reply: Service is started */
#define DBUS_START_REPLY_ALREADY_RUNNING  2u         /**< StartServiceByName reply: Service is already running */
// @}


#endif // _ALLJOYN_DBUSSTD_DEFINES_H
