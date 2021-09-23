/**
 * @file
 * This file defines a class for message bus data types and values
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
#ifndef _ALLJOYN_C_MSGARG_H
#define _ALLJOYN_C_MSGARG_H

#include <alljoyn_c/AjAPI.h>
#include <stdarg.h>
#include <alljoyn_c/Status.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Definition for a message arg.
 * alljoyn_msgarg deals with the message bus types and the operations on them.
 *
 * alljoyn_msgargs are designed to be light-weight. An alljoyn_msgarg will normally hold references to
 * the data (strings etc.) it wraps and will only copy that data if the alljoyn_msgarg is copied. For
 * example no additional memory is allocated for an #ALLJOYN_STRING that references an existing
 * const char*. If an alljoyn_msgarg is copied using the alljoyn_msgarg_copy function the destination
 * receives a copy of the contents of the source. The alljoyn_msgarg_stabilize function can also be
 * called to explicitly force contents of the alljoyn_msgarg to be copied into the alljoyn_msgarg.
 */
typedef struct _alljoyn_msgarg_handle* alljoyn_msgarg;

/**
 * Enumeration of the various message arg types.
 * @remark Most of these map directly to the values used in the
 * DBus wire protocol but some are specific to the AllJoyn implementation.
 */
typedef enum {
    ALLJOYN_INVALID          =  0,     ///< AllJoyn INVALID typeId
    ALLJOYN_ARRAY            = 'a',    ///< AllJoyn array container type
    ALLJOYN_BOOLEAN          = 'b',    ///< AllJoyn boolean basic type, @c 0 is @c FALSE and @c 1 is @c TRUE - Everything else is invalid
    ALLJOYN_DOUBLE           = 'd',    ///< AllJoyn IEEE 754 double basic type
    ALLJOYN_DICT_ENTRY       = 'e',    ///< AllJoyn dictionary or map container type - an array of key-value pairs
    ALLJOYN_SIGNATURE        = 'g',    ///< AllJoyn signature basic type
    ALLJOYN_HANDLE           = 'h',    ///< AllJoyn socket handle basic type
    ALLJOYN_INT32            = 'i',    ///< AllJoyn 32-bit signed integer basic type
    ALLJOYN_INT16            = 'n',    ///< AllJoyn 16-bit signed integer basic type
    ALLJOYN_OBJECT_PATH      = 'o',    ///< AllJoyn Name of an AllJoyn object instance basic type
    ALLJOYN_UINT16           = 'q',    ///< AllJoyn 16-bit unsigned integer basic type
    ALLJOYN_STRUCT           = 'r',    ///< AllJoyn struct container type
    ALLJOYN_STRING           = 's',    ///< AllJoyn UTF-8 NULL terminated string basic type
    ALLJOYN_UINT64           = 't',    ///< AllJoyn 64-bit unsigned integer basic type
    ALLJOYN_UINT32           = 'u',    ///< AllJoyn 32-bit unsigned integer basic type
    ALLJOYN_VARIANT          = 'v',    ///< AllJoyn variant container type
    ALLJOYN_INT64            = 'x',    ///< AllJoyn 64-bit signed integer basic type
    ALLJOYN_BYTE             = 'y',    ///< AllJoyn 8-bit unsigned integer basic type

    ALLJOYN_STRUCT_OPEN      = '(', /**< Never actually used as a typeId: specified as ALLJOYN_STRUCT */
    ALLJOYN_STRUCT_CLOSE     = ')', /**< Never actually used as a typeId: specified as ALLJOYN_STRUCT */
    ALLJOYN_DICT_ENTRY_OPEN  = '{', /**< Never actually used as a typeId: specified as ALLJOYN_DICT_ENTRY */
    ALLJOYN_DICT_ENTRY_CLOSE = '}', /**< Never actually used as a typeId: specified as ALLJOYN_DICT_ENTRY */

    ALLJOYN_BOOLEAN_ARRAY    = ('b' << 8) | 'a',   ///< AllJoyn array of booleans
    ALLJOYN_DOUBLE_ARRAY     = ('d' << 8) | 'a',   ///< AllJoyn array of IEEE 754 doubles
    ALLJOYN_INT32_ARRAY      = ('i' << 8) | 'a',   ///< AllJoyn array of 32-bit signed integers
    ALLJOYN_INT16_ARRAY      = ('n' << 8) | 'a',   ///< AllJoyn array of 16-bit signed integers
    ALLJOYN_UINT16_ARRAY     = ('q' << 8) | 'a',   ///< AllJoyn array of 16-bit unsigned integers
    ALLJOYN_UINT64_ARRAY     = ('t' << 8) | 'a',   ///< AllJoyn array of 64-bit unsigned integers
    ALLJOYN_UINT32_ARRAY     = ('u' << 8) | 'a',   ///< AllJoyn array of 32-bit unsigned integers
    ALLJOYN_INT64_ARRAY      = ('x' << 8) | 'a',   ///< AllJoyn array of 64-bit signed integers
    ALLJOYN_BYTE_ARRAY       = ('y' << 8) | 'a',   ///< AllJoyn array of 8-bit unsigned integers

    ALLJOYN_WILDCARD         = '*'     ///< This never appears in a signature but is used for matching arbitrary message args

} alljoyn_typeid;

/**
 * Create a new message argument.
 * calling alljoyn_msgarg_create() is the same as calling
 * alljoyn_msgarg_array_create(1).
 *
 * @return the created message argument
 */
extern AJ_API alljoyn_msgarg AJ_CALL alljoyn_msgarg_create();

/**
 * Build a message argument that has its value already set. If the setting the
 * message argument value fails for any reason the message argument type will be
 * set to #ALLJOYN_INVALID. See the description of the #alljoyn_msgarg_set() function
 * for information about the signature and parameters. For initializing complex
 * values it is recommended to use the alljoyn_msgarg_create and alljoyn_msgarg_set
 * functions so the success of setting the value can be explicitly checked.
 *
 * @param signature   The signature for alljoyn_msgarg value.
 * @param ...         One or more values to initialize the alljoyn_msgarg.
 *
 * @return the created alljoyn_msgarg
 */
extern AJ_API alljoyn_msgarg CDECL_CALL alljoyn_msgarg_create_and_set(const char* signature, ...);

/**
 * Destroy a message argument.
 *
 * @param arg The message argument to destroy.
 */
extern AJ_API void AJ_CALL alljoyn_msgarg_destroy(alljoyn_msgarg arg);

/**
 * Create an array of message arguments
 *
 * This returns and alljoyn_msgarg however the individual array elements can only
 * be accessed using alljoyn_msgarg_array_element() function.
 *
 * the alljoyn_msgarg returned can be used in any functions that states says
 * alljoyn_msgarg_array_*.  and alljoyn_msgarg created using alljoyn_msgarg_create()
 * is an array of message arguments with size of 1.
 *
 * If the function does not specifically say it is for an array it is assumed that
 * the message argument was created using alljoyn_msgarg_create() and will be treated
 * like an array with only one element.
 *
 * For example the following code would only copy the first msgarg in the array.
 * An alljoyn_msgarg of the string "hello". Not both array elements.
 *
 * @code
 * alljoyn_msgarg args = alljoyn_msgarg_array_create(2);
 * alljoyn_msgarg_array_set(args, 2, "ss", "hello", "world");
 * alljoyn_msgarg arg = alljoyn_msgarg_copy(args);
 * @endcode
 *
 * To make a copy of an alljoyn_msgarg that contains an array of elements requires
 * a for loop.
 *
 * @code
 * alljoyn_msgarg args = alljoyn_msgarg_array_create(2);
 * alljoyn_msgarg_array_set(args, 2, "ss", "hello", "world");
 * alljoyn_msgarg cp_args = alljoyn_msgarg_array_create(2);
 * for (size_t i = 0; i < 2; ++i) {
 *     alljoyn_msgarg_array_element(cp_args, i) = alljoyn_msgarg_copy(alljoyn_msgarg_array_element(args, i));
 * }
 * @endcode
 *
 * @param size the size of the array of alljoyn_msgargs
 *
 * @return the created array of message arguments
 */
extern AJ_API alljoyn_msgarg AJ_CALL alljoyn_msgarg_array_create(size_t size);

/**
 * when working with an array of message arguments this will return the nth item
 * in the array.
 * @param arg   the alljoyn_msgarg that contains an array of msgargs
 * @param index the index number of the element we wish to access.
 *
 * @return the individual alljoyn_msgarg specified by the index
 */
extern AJ_API alljoyn_msgarg AJ_CALL alljoyn_msgarg_array_element(alljoyn_msgarg arg, size_t index);

/**
 * Set value of a message arg from a signature and a list of values. Note that any values or
 * alljoyn_msgarg pointers passed in must remain valid until this alljoyn_msgarg is freed using
 * alljoyn_msgarg_delete.
 *
 *  - @c 'a'  The array length followed by:
 *            - If the element type is a basic type a pointer to an array of values of that type.
 *            - If the element type is string a pointer to array of const char*, if array length is
 *              non-zero, and the char* pointer is NULL, the NULL must be followed by a pointer to
 *              an array of const qcc::String.
 *            - If the element type is an @ref ALLJOYN_ARRAY "ARRAY", @ref ALLJOYN_STRUCT "STRUCT",
 *              @ref ALLJOYN_DICT_ENTRY "DICT_ENTRY" or @ref ALLJOYN_VARIANT "VARIANT" a pointer to an
 *              array of alljoyn_msgargs where each alljoyn_msgarg has the signature specified by the
 *              element type.
 *            - If the element type is specified using the wildcard character '*', a pointer to
 *              an  array of alljoyn_msgargs. The array element type is determined from the type of the
 *              first alljoyn_msgarg in the array, all the elements must have the same type.
 *  - @c 'b'  A bool value
 *  - @c 'd'  A double (64 bits)
 *  - @c 'g'  A pointer to a NUL terminated string (pointer must remain valid for lifetime of the alljoyn_msgarg)
 *  - @c 'h'  A qcc::SocketFd
 *  - @c 'i'  An int (32 bits)
 *  - @c 'n'  An int (16 bits)
 *  - @c 'o'  A pointer to a NUL terminated string (pointer must remain valid for lifetime of the alljoyn_msgarg)
 *  - @c 'q'  A uint (16 bits)
 *  - @c 's'  A pointer to a NUL terminated string (pointer must remain valid for lifetime of the alljoyn_msgarg)
 *  - @c 't'  A uint (64 bits)
 *  - @c 'u'  A uint (32 bits)
 *  - @c 'v'  Not allowed, the actual type must be provided.
 *  - @c 'x'  An int (64 bits)
 *  - @c 'y'  A byte (8 bits)
 *
 *  - @c '(' and @c ')'  The list of values that appear between the parentheses using the notation above
 *  - @c '{' and @c '}'  A pair values using the notation above.
 *
 *  - @c '*'  A pointer to an alljoyn_msgarg.
 *
 * Examples:
 *
 * An array of strings
 *
 *     @code
 *     char* fruits[3] =  { "apple", "banana", "orange" };
 *     alljoyn_msgarg bowl;
 *     bowl = alljoyn_msgarg_create();
 *     alljoyn_msgarg_set(bowl, "as", 3, fruits);
 *     @endcode
 *
 * A struct with a uint and two string elements.
 *
 *     @code alljoyn_msgarg_set(arg, "(uss)", 1024, "hello", "world"); @endcode
 *
 * An array of 3 dictionary entries where each entry has an integer key and string value.
 *
 *     @code
 *     alljoyn_msgarg dict = alljoyn_msgarg_array_create(3)
 *     alljoyn_msgarg_set(alljoyn_msgarg_array_element(0), "{is}", 1, "red");
 *     alljoyn_msgarg_set(alljoyn_msgarg_array_element(1), "{is}", 2, "green");
 *     alljoyn_msgarg_set(alljoyn_msgarg_array_element(2), "{is}", 3, "blue");
 *     alljoyn_msgarg arg = alljoyn_msgarg_create();
 *     alljoyn_msgarg_set(arg, "a{is}", 3, dict);
 *     @endcode
 *
 * An array of uint_16's
 *
 *     @code
 *     uint16_t aq[] = { 1, 2, 3, 5, 6, 7 };
 *     alljoyn_msgarg_set(arg, "aq", sizeof(aq) / sizeof(uint16_t), aq);
 *     @endcode
 *
 * @param arg         The alljoyn_msgarg being set
 * @param signature   The signature for alljoyn_msgarg value
 * @param ...         One or more values to initialize the alljoyn_msgarg.
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus CDECL_CALL alljoyn_msgarg_set(alljoyn_msgarg arg, const char* signature, ...);

/**
 * Matches a signature to the alljoyn_msgarg and if the signature matches unpacks the component
 * values of an alljoyn_msgarg. Note that the values returned are references into the
 * alljoyn_msgarg itself so unless copied will become invalid if the alljoyn_msgarg is freed or
 * goes out of scope.  This function resolves through variants, so if the alljoyn_msgarg is a
 * variant that references a 32 bit integer it can be unpacked directly into a 32 bit integer
 * pointer.
 *
 *  - @c 'a'  A pointer to a length of type size_t that returns the number of elements in the array followed by:
 *            - If the element type is a scalar type a pointer to a pointer of the correct type for the values.
 *            - Otherwise a pointer to a pointer to an alljoyn_msgarg.
 *
 *  - @c 'b'  A pointer to a bool
 *  - @c 'd'  A pointer to a double (64 bits)
 *  - @c 'g'  A pointer to a char*  (character string is valid for the lifetime of the alljoyn_msgarg)
 *  - @c 'h'  A pointer to a qcc::SocketFd
 *  - @c 'i'  A pointer to a uint32_t
 *  - @c 'n'  A pointer to an int16_t
 *  - @c 'o'  A pointer to a char*  (character string is valid for the lifetime of the alljoyn_msgarg)
 *  - @c 'q'  A pointer to a uint16_t
 *  - @c 's'  A pointer to a char*  (character string is valid for the lifetime of the alljoyn_msgarg)
 *  - @c 't'  A pointer to a uint64_t
 *  - @c 'u'  A pointer to a uint32_t
 *  - @c 'v'  A pointer to a pointer to an alljoyn_msgarg, matches to a variant but returns a pointer to
 *            the alljoyn_msgarg of the underlying real type.
 *  - @c 'x'  A pointer to an int64_t
 *  - @c 'y'  A pointer to a uint8_t
 *
 *  - @c '(' and @c ')'  A list of pointers as required for each of the struct members.
 *  - @c '{' and @c '}'  Pointers as required for the key and value members.
 *
 *  - @c '*' A pointer to a pointer to an alljoyn_msgarg. This matches any value type.
 *
 * Examples:
 *
 * A struct with and uint32 and two string elements.
 *
 *     @code
 *     struct {
 *         uint32_t i;
 *         char *hello;
 *         char *world;
 *     } myStruct;
 *     alljoyn_msgarg_get(arg, "(uss)", &myStruct.i, &myStruct.hello, &myStruct.world);
 *     @endcode
 *
 * A variant where it is known that the value is a uint32, a string, or double. Note that the
 * variant is resolved away.
 *
 *     @code
 *     uint32_t i;
 *     double d;
 *     char *str;
 *     QStatus status = alljoyn_msgarg_get(arg, "i", &i);
 *     if (status == ER_BUS_SIGNATURE_MISMATCH) {
 *         status = alljoyn_msgarg_get(arg, "s", &str);
 *         if (status == ER_BUS_SIGNATURE_MISMATCH) {
 *             status = alljoyn_msgarg_get(arg, "d", &d);
 *         }
 *     }
 *     @endcode
 *
 * An array of dictionary entries where each entry has an integer key and variant. Find the
 * entries where the variant value is a string or a struct of 2 strings.
 *
 *     @code
 *     alljoyn_msgarg entries;
 *     size_t num;
 *     alljoyn_msgarg_get(arg, "a{iv}", &num, &entries);
 *     for (size_t i = 0; i < num; ++i) {
 *         char *str1;
 *         char *str2;
 *         uint32_t key;
 *         status = alljoyn_msgarg_get(alljoyn_msgarg_array_element(entries, i), "{is}", &key, &str1);
 *         if (status == ER_BUS_SIGNATURE_MISMATCH) {
 *             status = alljoyn_msgarg_get(alljoyn_msgarg_array_element(entries, i), "{i(ss)}", &key, &str1, &str2);
 *         }
 *     }
 *     @endcode
 *
 * An array of uint_16's
 *
 *     @code
 *     uint16_t *vals;
 *     size_t numVals;
 *     alljoyn_msgarg_get(arg, "aq", &numVals, &vals);
 *     @endcode
 *
 * @param arg         The alljoyn_msgarg we are reading from
 * @param signature   The signature for alljoyn_msgarg value
 * @param ...         Pointers to return the unpacked values.
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus CDECL_CALL alljoyn_msgarg_get(alljoyn_msgarg arg, const char* signature, ...);

/**
 * create a copy of a message argument.  This will create a new alljoyn_msgarg and
 * must be cleaned up using alljoyn_msgarg_detroy.
 *
 * @param source      the alljoyn_msgarg to be copied
 *
 * @return copy of the source message argument is returned
 */
extern AJ_API alljoyn_msgarg AJ_CALL alljoyn_msgarg_copy(const alljoyn_msgarg source);

/**
 * Copy the contents of the source alljoyn_msgarg into the Destination alljoyn_msgarg. If the
 * destination already contains information it will be cleared before the source
 * alljoyn_msgarg is copied in.
 *
 * @param destination the alljoyn_msgarg that will hold the copy
 * @param source      the alljoyn_msgarg to be copied
 */
extern AJ_API void AJ_CALL alljoyn_msgarg_clone(alljoyn_msgarg destination, const alljoyn_msgarg source);
/**
 * Equality operator.
 *
 * @param lhv  The alljoyn_msgarg to compare.
 * @param rhv  The other alljoyn_msgarg to compare
 *
 * @return  Returns true if the two message args have the same signatures and values.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_msgarg_equal(alljoyn_msgarg lhv, alljoyn_msgarg rhv);



/**
 * Set an array of alljoyn_msgargs by applying the alljoyn_msgarg_set() function to each alljoyn_msgarg in turn.
 *
 * @param args     An array of alljoyn_msgargs to set.
 * @param numArgs  [in,out] On input the size of the args array. On output the number of alljoyn_msgargs
 *                 that were set. There must be at least enough alljoyn_msgargs to completely
 *                 initialize the signature.
 *
 * @param signature   The signature for alljoyn_msgarg values
 * @param ...         One or more values to initialize the alljoyn_msgarg list.
 *
 * @return
 *       - #ER_OK if the alljoyn_msgargs were successfully set.
 *       - #ER_BUS_TRUNCATED if the signature was longer than expected.
 *       - Other error status codes indicating a failure.
 */
extern AJ_API QStatus CDECL_CALL alljoyn_msgarg_array_set(alljoyn_msgarg args, size_t* numArgs, const char* signature, ...);

/**
 * Unpack an array of alljoyn_msgargs by applying the alljoyn_msgarg_get() function to each alljoyn_msgarg in turn.
 *
 * @param args       An array of alljoyn_msgargs to unpack.
 * @param numArgs    The size of the alljoyn_msgargs array.
 * @param signature  The signature to match against the alljoyn_msgarg values
 * @param ...         Pointers to return references to the unpacked values.
 *
 * @return
 *      - #ER_OK if the alljoyn_msgargs were successfully set.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - Other error status codes indicating a failure.
 */
extern AJ_API QStatus CDECL_CALL alljoyn_msgarg_array_get(const alljoyn_msgarg args, size_t numArgs, const char* signature, ...);

/**
 * Returns an XML string representation of this type
 *
 * @param[in]  arg    The message arg to generate the XML string representation of
 * @param[out] str    The character string that will hold the XML string
 *               representation of the alljoyn_msgarg
 * @param[in]  buf    The size of the char* array that will hold the string
 * @param[in]  indent Number of spaces to indent the generated xml (default value 0)
 *
 * @return  The number of characters (including the terminating nul byte) which
 *          would have been written to the final string if enough space
 *          available.  Thus returning a value of buf or larger means the output
 *          was truncated.
 */
extern AJ_API size_t AJ_CALL alljoyn_msgarg_tostring(alljoyn_msgarg arg, char* str, size_t buf, size_t indent);

/**
 * Returns an XML string representation for an array of message args.
 *
 * @param[in]  args     The message arg array to generate the XML string representation of
 * @param[in]  numArgs  The size of the message arg array.
 * @param[out] str      The character string that will hold the XML string
 *                      representation of the alljoyn_msgarg array
 * @param[in]  buf      The size of the char* array that will hold the string
 * @param[in]  indent   Number of spaces to indent the generated xml (default value 0)
 *
 * @return  The number of characters (including the terminating nul byte) which
 *          would have been written to the final string if enough space is
 *          available.  Thus returning a value of buf or larger means the output
 *          was truncated.
 */
extern AJ_API size_t AJ_CALL alljoyn_msgarg_array_tostring(const alljoyn_msgarg args, size_t numArgs, char* str, size_t buf, size_t indent);

/**
 * Returns a string for the signature of this value
 *
 * @param[in] arg the argument to read the signature from
 * @param[out] str a string containing the signature of the alljoyn_msgarg use NULL pointer
 *            to find string size.
 * @param[in] buf The size of the char* array that will hold the string
 *
 * @return  The number of characters (including the terminating nul byte) which
 *          would have been written to the final string if enough space is
 *          available.  Thus returning a value of buf or larger means the output
 *          was truncated.
 */
extern AJ_API size_t AJ_CALL alljoyn_msgarg_signature(alljoyn_msgarg arg, char* str, size_t buf);

/**
 * Returns a string representation of the signature of an array of message args.
 *
 * @param[in] values    A pointer to an array of message arg values
 * @param[in] numValues  Length of the array
 * @param[out] str       a string containing the signature of the alljoyn_msgarg use NULL
 *                       pointer to find string size.
 * @param[in] buf        The size of the char* array that will hold the string
 *
 * @return  The number of characters (including the terminating nul byte) which
 *          would have been written to the final string if enough space is
 *          available.  Thus returning a value of buf or larger means the output
 *          was truncated.
 */
extern AJ_API size_t AJ_CALL alljoyn_msgarg_array_signature(alljoyn_msgarg values, size_t numValues, char* str, size_t buf);

/**
 * Checks the signature of this arg.
 *
 * @param arg        The message argument we want to check the signature of
 * @param signature  The signature to check
 *
 * @return  true if this arg has the specified signature, otherwise returns false.
 */
extern AJ_API QCC_BOOL AJ_CALL alljoyn_msgarg_hassignature(alljoyn_msgarg arg, const char* signature);

/**
 * Helper function for accessing dictionary elements. The alljoyn_msgarg must be an array of dictionary
 * elements. The second parameter is the key value, this is expressed according to the rules for
 * alljoyn_msgarg_set so is either a scalar, a pointer to a string, or for 64 bit values a pointer to
 * the value. This value is matched against the dictionary array to locate the matching element.
 * The third and subsequent parameters are unpacked according to the rules of alljoyn_msgarg_get.
 *
 * For example, where the key is a string and the values are structs:
 *
 *     @code
 *     uint8_t age;
 *     uint32_t height;
 *     const char* address;
 *     QStatus status = alljoyn_msgarg_getdictelement(arg, "{s(yus)}", "fred", &age, &height,  &address);
 *     @endcode
 *
 * This function is particularly useful for extracting specific properties from the array of property
 * values returned by ProxyBusObject::GetAllProperties.
 *
 * @param arg      a message argument containing an array of dictionary elements
 * @param elemSig  The expected signature for the dictionary element, e.g. "{su}"
 * @param ...      Pointers to return unpacked key values.
 *
 * @return
 *      - #ER_OK if the dictionary signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_NOT_A_DICTIONARY if this function is called on an alljoyn_msgarg that is not a dictionary.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - #ER_BUS_ELEMENT_NOT_FOUND if the key was not found in the dictionary.
 *      - An error status otherwise
 */
extern AJ_API QStatus CDECL_CALL alljoyn_msgarg_getdictelement(alljoyn_msgarg arg, const char* elemSig, ...);

/**
 * Get the alljoyn_typeid of the alljoyn_msgarg
 *
 * @param arg the message argument we want to know the alljoyn_typeid of.
 *
 * @return the alljoyn_typeid of the alljoyn_msgarg
 */
extern AJ_API alljoyn_typeid AJ_CALL alljoyn_msgarg_gettype(alljoyn_msgarg arg);

/**
 * Clear the alljoyn_msgarg setting the type to ALLJOYN_INVALID and freeing any memory allocated for the
 * alljoyn_msgarg value.
 *
 * @param arg the message argument to be cleared.
 */
extern AJ_API void AJ_CALL alljoyn_msgarg_clear(alljoyn_msgarg arg);

/**
 * Makes an alljoyn_msgarg stable by completely copying the contents into locally
 * managed memory. After an alljoyn_msgarg has been stabilized any values used to
 * initialize or set the message arg can be freed.
 *
 * @param arg the message argument to stabilize
 */
extern AJ_API void AJ_CALL alljoyn_msgarg_stabilize(alljoyn_msgarg arg);

/// @cond ALLJOYN_DEV
/*
 *******************************************************************************
 * This set of functions were originally designed for the alljoyn_unity bindings
 * however they did not not properly map with the C++ MsgArg Class.
 *
 * No Functions below this point should be used by any code except for the
 * AllJoyn Unity Extension. The functions could be changed at any time.
 *******************************************************************************
 */
/**
 * Set an array of alljoyn_msgargs by applying the alljoyn_msgarg_set() function
 * to each alljoyn_msgarg in turn.
 *
 * @param args        An array of alljoyn_msgargs to set.
 * @param argOffset   Offset from the start of the alljoyn_msgarg array.
 * @param numArgs     [in,out] On input the number of args to set. On output the number of alljoyn_msgargs
 *                    that were set. There must be at least enough alljoyn_msgargs to completely
 *                    initialize the signature.
 *                    there should at least enough.
 * @param signature   The signature for alljoyn_msgarg values
 * @param ...         One or more values to initialize the alljoyn_msgarg list.
 *
 * @return
 *       - #ER_OK if the alljoyn_msgargs were successfully set.
 *       - #ER_BUS_TRUNCATED if the signature was longer than expected.
 *       - Other error status codes indicating a failure.
 */
extern AJ_API QStatus CDECL_CALL alljoyn_msgarg_array_set_offset(alljoyn_msgarg args, size_t argOffset, size_t* numArgs, const char* signature, ...);

/**
 * This function is identical to alljoyn_msgarg_set except after the values
 * in the message arg have been set the alljoyn_msgarg will be stabilized.
 * This is useful when the call is made from a manage language like C sharp where
 * objects like strings may be garbage collected.
 *
 * @param arg         The alljoyn_msgarg being set
 * @param signature   The signature for alljoyn_msgarg value
 * @param ...         One or more values to initialize the alljoyn_msgarg.
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus CDECL_CALL alljoyn_msgarg_set_and_stabilize(alljoyn_msgarg arg, const char* signature, ...);
/*******************************************************************************
 * MsgArg set functions for each of the basic data types
 *******************************************************************************/
/**
 * Set the value of an alljoyn_msgarg to hold an uint8 (byte).
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the uint8 (byte)
 * @param y       a  uint8
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg walljoyn_msgargcessfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_uint8(alljoyn_msgarg arg, uint8_t y);
/**
 * Set the value of an alljoyn_msgarg to hold a QCC_BOOL.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the QCC_BOOL
 * @param b       a QCC_BOOL
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_bool(alljoyn_msgarg arg, QCC_BOOL b);
/**
 * Set the value of an alljoyn_msgarg to hold an int16.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the int16
 * @param n       an int16
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_int16(alljoyn_msgarg arg, int16_t n);
/**
 * Set the value of an alljoyn_msgarg to hold an uint16.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the uint16
 * @param q       an uint16
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_uint16(alljoyn_msgarg arg, uint16_t q);
/**
 * Set the value of an alljoyn_msgarg to hold an int32.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the int32
 * @param i       an int32
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_int32(alljoyn_msgarg arg, int32_t i);
/**
 * Set the value of an alljoyn_msgarg to hold an uint32.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the uint32
 * @param u       an uint32
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_uint32(alljoyn_msgarg arg, uint32_t u);
/**
 * Set the value of an alljoyn_msgarg to hold an int64.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the int64
 * @param x       an int64
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_int64(alljoyn_msgarg arg, int64_t x);
/**
 * Set the value of an alljoyn_msgarg to hold an uint64.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the uint64
 * @param t       an uint64
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_uint64(alljoyn_msgarg arg, uint64_t t);
/**
 * Set the value of an alljoyn_msgarg to hold an double.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the double
 * @param d       an double
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_double(alljoyn_msgarg arg, double d);
/**
 * Set the value of an alljoyn_msgarg to hold a string.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the string
 * @param s       an string
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_string(alljoyn_msgarg arg, const char* s);
/**
 * Set the value of an alljoyn_msgarg to hold an object path
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the object path
 * @param o       an object path string
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_objectpath(alljoyn_msgarg arg, const char* o);
/**
 * Set the value of an alljoyn_msgarg to hold a signature.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg that will hold the signature
 * @param g       a signature string
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_signature(alljoyn_msgarg arg, const char* g);

/*******************************************************************************
 * MsgArg get functions for each of the basic data types
 *******************************************************************************/
/**
 * Get an uint8 (bytes) from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] y    a pointer to the uint8 (byte)
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_uint8(const alljoyn_msgarg arg, uint8_t* y);
/**
 * Get a QCC_BOOL from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] b    a pointer to the QCC_BOOL
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_bool(const alljoyn_msgarg arg, QCC_BOOL* b);
/**
 * Get an int16 from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] n    a pointer to the int16
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_int16(const alljoyn_msgarg arg, int16_t* n);
/**
 * Get an uint16 from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] q    a pointer to the uint16
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_uint16(const alljoyn_msgarg arg, uint16_t* q);
/**
 * Get an int32 from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] i    a pointer to the int32
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_int32(const alljoyn_msgarg arg, int32_t* i);
/**
 * Get an uint32 from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] u    a pointer to the uint32
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_uint32(const alljoyn_msgarg arg, uint32_t* u);
/**
 * Get an int64 from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] x    a pointer to the int64
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_int64(const alljoyn_msgarg arg, int64_t* x);
/**
 * Get an uint64 from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] t    a pointer to the uint64
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_uint64(const alljoyn_msgarg arg, uint64_t* t);
/**
 * Get a double from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] d    a pointer to the double
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_double(const alljoyn_msgarg arg, double* d);
/**
 * Get a string from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] s    a pointer to the string
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_string(const alljoyn_msgarg arg, char** s);
/**
 * Get an object path from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] o    a pointer to the object path string
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_objectpath(const alljoyn_msgarg arg, char** o);
/**
 * Get a signature from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] g    a pointer to the signature string
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_signature(const alljoyn_msgarg arg, char** g);

/**
 * Get the alljoyn_msgarg from an variant alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg  the alljoyn_msgarg to obtain the data from
 * @param[out] v    the alljoyn_msgarg that will be returned
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_variant(const alljoyn_msgarg arg, alljoyn_msgarg v);

/*******************************************************************************
 * MsgArg set function for arrays of each basic data type
 *******************************************************************************/
/**
 * Set the value of an alljoyn_msgarg to hold an array of uint8s (bytes).
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of uint8s (bytes)
 * @param ay      a pointer to an array of uint8s (bytes)
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_uint8_array(alljoyn_msgarg arg, size_t length, uint8_t* ay);
/**
 * Set the value of an alljoyn_msgarg to hold an array of QCC_BOOLs.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of QCC_BOOLs
 * @param ab      a pointer to an array of QCC_BOOLs
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_bool_array(alljoyn_msgarg arg, size_t length, QCC_BOOL* ab);
/**
 * Set the value of an alljoyn_msgarg to hold an array of int16s.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of int16s
 * @param an      a pointer to an array of int16s
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_int16_array(alljoyn_msgarg arg, size_t length, int16_t* an);
/**
 * Set the value of an alljoyn_msgarg to hold an array of uint16s.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of uint16s
 * @param aq      a pointer to an array of uint16s
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_uint16_array(alljoyn_msgarg arg, size_t length, uint16_t* aq);
/**
 * Set the value of an alljoyn_msgarg to hold an array of int32s.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of int32s
 * @param ai      a pointer to an array of int32s
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_int32_array(alljoyn_msgarg arg, size_t length, int32_t* ai);
/**
 * Set the value of an alljoyn_msgarg to hold an array of uint32s.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of uint32s
 * @param au      a pointer to an array of uint32s
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_uint32_array(alljoyn_msgarg arg, size_t length, uint32_t* au);
/**
 * Set the value of an alljoyn_msgarg to hold an array of int64s.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of int64s
 * @param ax      a pointer to an array of int64s
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_int64_array(alljoyn_msgarg arg, size_t length, int64_t* ax);
/**
 * Set the value of an alljoyn_msgarg to hold an array of uint64s.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of uint64s
 * @param at      a pointer to an array of uint64s
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_uint64_array(alljoyn_msgarg arg, size_t length, uint64_t* at);
/**
 * Set the value of an alljoyn_msgarg to hold an array of doubles.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of dobules
 * @param ad      a pointer to an array of doubles
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_double_array(alljoyn_msgarg arg, size_t length, double* ad);
/**
 * Set the value of an alljoyn_msgarg to hold an array of strings.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of object paths
 * @param as      a pointer to an array of object paths
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_string_array(alljoyn_msgarg arg, size_t length, const char** as);
/**
 * Set the value of an alljoyn_msgarg to hold an array of object paths.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param arg     the alljoyn_msgarg to set
 * @param length  the size of the array of object paths
 * @param ao      a pointer to an array of object paths
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_objectpath_array(alljoyn_msgarg arg, size_t length, const char** ao);
/**
 * Set the value of an alljoyn_msgarg to hold an array of signatures.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 *
 * @param      arg     the alljoyn_msgarg to set
 * @param[out] length  the size of the array of signatures
 * @param[out] ag      a pointer to an array of signatures
 *
 * @return
 *      - #ER_OK if the alljoyn_msgarg was successfully set
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_set_signature_array(alljoyn_msgarg arg, size_t length, const char** ag);

/*******************************************************************************
 * MsgArg get function for arrays of each basic data type
 *******************************************************************************/
/**
 * get an array of uint8s (bytes) from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param[out] length  the size of the uint8 (byte) array
 * @param[out] ay      a pointer to the uint8 (byte) array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_uint8_array(const alljoyn_msgarg arg, size_t* length, uint8_t* ay);
/**
 * get an array of QCC_BOOLs from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param[out] length  the size of the QCC_BOOL array
 * @param[out] ab      a pointer to the QCC_BOOL array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_bool_array(const alljoyn_msgarg arg, size_t* length, QCC_BOOL* ab);
/**
 * get an array of int16 from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param[out] length  the size of the int16 array
 * @param[out] an      a pointer to the int16 array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_int16_array(const alljoyn_msgarg arg, size_t* length, int16_t* an);
/**
 * get an array of uint16s from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param[out] length  the size of the uint16 array
 * @param[out] aq      a pointer to the uint16 array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_uint16_array(const alljoyn_msgarg arg, size_t* length, uint16_t* aq);
/**
 * get an array of int32 from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param[out] length  the size of the int32 array
 * @param[out] ai      a pointer to the int32 array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_int32_array(const alljoyn_msgarg arg, size_t* length, int32_t* ai);
/**
 * get an array of uint32 from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param[out] length  the size of the uint32 array
 * @param[out] au      a pointer to the uint32 array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_uint32_array(const alljoyn_msgarg arg, size_t* length, uint32_t* au);
/**
 * get an array of int64s from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param[out] length  the size of the int64 array
 * @param[out] ax      a pointer to the int64 array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_int64_array(const alljoyn_msgarg arg, size_t* length, int64_t* ax);
/**
 * get an array of uint64s from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param[out] length  the size of the uint64 array
 * @param[out] at      a pointer to the uint64 array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_uint64_array(const alljoyn_msgarg arg, size_t* length, uint64_t* at);
/**
 * get an array of doubles from an alljoyn_msgarg
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param[out] length  the size of the double array
 * @param[out] ad      a pointer to the double array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_double_array(const alljoyn_msgarg arg, size_t* length, double* ad);

/**
 * get an array of alljoyn_msgargs from an alljoyn_msgarg.
 *
 * This function can be used for any array that contains an array of alljoyn_msgargs.
 * This would be non-scalar arrays. i.e. as, ao, ag, a{is}, av etc.
 *
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_get.
 *
 * @param      arg     the alljoyn_msgarg to obtain the data from
 * @param      arg     the signature of the array
 * @param[out] length  the size of the array
 * @param[out] av      a pointer to the alljoyn_msgarg array
 *
 * @return
 *      - #ER_OK if the signature matched and alljoyn_msgarg was successfully unpacked.
 *      - #ER_BUS_SIGNATURE_MISMATCH if the signature did not match.
 *      - An error status otherwise
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_get_variant_array(const alljoyn_msgarg arg, const char* signature, size_t* length, alljoyn_msgarg* av);

/*******************************************************************************
 * MsgArg get functions for Arrays of Arrays
 *******************************************************************************/
/**
 * How many elements are in the alljoyn array
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 * @see alljoyn_msgarg_get.
 *
 * @param arg The alljoyn_msgarg that contains the array elements
 *
 * @return the number of elements in the alljoyn_msgarg
 */
extern AJ_API size_t AJ_CALL alljoyn_msgarg_get_array_numberofelements(const alljoyn_msgarg arg);
/**
 * Obtain a single alljoyn_msgarg element from an array of alljoyn_msgarg elements
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 * @see alljoyn_msgarg_get.
 *
 * @param      arg      The alljoyn_msgarg that contains the array element
 * @param      index    The index value for the individual alljoyn_msgarg
 * @param[out] element  The alljoyn_msgarg located at the index
 */
extern AJ_API void AJ_CALL   alljoyn_msgarg_get_array_element(const alljoyn_msgarg arg, size_t index, alljoyn_msgarg* element);
/**
 * Obtain the signature of an element inside an array of alljoyn_msgargs
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 * @see alljoyn_msgarg_set
 * @see alljoyn_msgarg_get.
 *
 * @param arg     The alljoyn_msgarg that contains the signature
 * @param index   The index value for the individual alljoyn_msgarg
 *
 * @return the string representing the signature of the element
 */
extern AJ_API const char* AJ_CALL alljoyn_msgarg_get_array_elementsignature(const alljoyn_msgarg arg, size_t index);


/*******************************************************************************
 * MsgArg functions for dictionaries
 *******************************************************************************/
/*
 * Obtain the alljoyn_msgarg used as the key for a key/value pair in an AllJoyn
 * dictionary entry.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 *
 * @param arg An alljoyn_msgarg that contains a single key/value pair dictionary
 *            entry.
 *
 * @return an alljoyn_msgarg containing the key portion of a key/value pair
 */
extern AJ_API alljoyn_msgarg AJ_CALL alljoyn_msgarg_getkey(alljoyn_msgarg arg);

/*
 * Obtain the alljoyn_msgarg used as the value for a key/value pair in an AllJoyn
 * dictionary entry.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 *
 * @param arg An alljoyn_msgarg that contains a single key/value pair dictionary
 *            entry.
 *
 * @return an alljoyn_msgarg containing the value portion of a key/value pair
 */
extern AJ_API alljoyn_msgarg AJ_CALL alljoyn_msgarg_getvalue(alljoyn_msgarg arg);

/*
 * Create a key/value pair for an AllJoyn dictionary entry.
 *
 * the alljoyn_msgargs used for the key and value will be copied into the arg
 * and will not be managed by the alljoyn_msgarg arg.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 *
 * @param arg    The alljoyn_msgarg to set with a key/value pair
 * @param key    An alljoyn_msgarg containing the key in a key/value pair
 * @param value  An alljoyn_msgarg containing the value in a key/value pair
 *
 * @return #ER_OK
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_setdictentry(alljoyn_msgarg arg, alljoyn_msgarg key, alljoyn_msgarg value);

/*******************************************************************************
 * MsgArg functions for structs
 *******************************************************************************/
/*
 * Set the values for an AllJoyn Struct entry.
 * an AllJoyn struct is passed in as an array of alljoyn_msgargs with each element
 * representing a member of the struct.
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 *
 * @param arg            an alljoyn_msgarg that will hold the values of the struct
 * @param struct_members an alljoyn_msgarg array that represents a struct
 * @param num_members    the number of members in the struct
 *
 * @return #ER_OK
 */
extern AJ_API QStatus AJ_CALL alljoyn_msgarg_setstruct(alljoyn_msgarg arg, alljoyn_msgarg struct_members, size_t num_members);

/*
 * Obtain the number of members in an AllJoyn struct
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 *
 * @param arg the alljoyn_msgarg containing a struct
 *
 * @return the number of members contained in the struct
 */
extern AJ_API size_t AJ_CALL alljoyn_msgarg_getnummembers(alljoyn_msgarg arg);
/*
 * obtain the member of an AllJoyn struct at the index location
 * @remark This function exists for development of other language bindings and may
 *         be changed or removed in future updates and should not be used for reading
 *         values from an alljoyn_msgarg.
 *
 * @param arg   the alljoyn_msgarg containing a struct
 * @param index the index of the member
 *
 * @return the alljoyn_msgarg at the index
 */
extern AJ_API alljoyn_msgarg AJ_CALL alljoyn_msgarg_getmember(alljoyn_msgarg arg, size_t index);

/// @endcond
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
