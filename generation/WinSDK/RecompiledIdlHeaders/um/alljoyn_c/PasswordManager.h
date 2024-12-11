/**
 * @file PasswordManager.h is the top-level object that provides the interface to
 * set credentials used for the authentication of thin clients.
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
#ifndef _ALLJOYN_C_PASSWORDMANAGER_H
#define _ALLJOYN_C_PASSWORDMANAGER_H

#include <alljoyn_c/AjAPI.h>
#include <alljoyn_c/Status.h>

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Set credentials used for the authentication of thin clients.
 *
 * @warning Before invoking Connect() to BusAttachment, the application should call SetCredentials
 * if it expects to be able to communicate to/from thin clients.
 * The bundled router will start advertising the name as soon as it is started and MUST have
 * the credentials set to be able to authenticate any thin clients that may try to use the
 * bundled router to communicate with the app.
 * @param authMechanism  The name of the authentication mechanism issuing the request.
 * @param password       The password.
 *
 * @return
 *      - #ER_OK  if the credentials was successfully set.
 */
extern AJ_API QStatus AJ_CALL alljoyn_passwordmanager_setcredentials(const char* authMechanism, const char* password);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif

