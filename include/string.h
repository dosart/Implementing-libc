/*!
@file
@defgroup string
@brief  Header file for string
This file contains functions implementation from libs (string.h)
*/
#ifndef IMPLEMENTING_LIBC_STRING_H
#define IMPLEMENTING_LIBC_STRING_H

#include <stddef.h>

/**
 * @ingroup string
 *
 * @brief Copies bytes between buffers. From src to dest.
 *
 * @param dest Destination area.
 * @param src Source area.
 * @param n, Bytes count.

 * @returns Pointer to dest.
 */
void *str_memcpy(void *dest, const void *src, size_t n);

/**
 * @ingroup string
 * 
 * @brief Sets buffers to a specified character.
 *
 * @param buf Pointer to the object to fill.
 * @param ch  Fill byte.
 * @param count  Number of bytes to fill.
 *
 * @return Pointer to buf.
 */
void *str_memset(void *buf, char ch, size_t count);

/**
 * @ingroup string
 *
 * @brief Compare strings.
 *
 * @param str1 Null-terminated string to compare.
 * @param str2 Null-terminated string to compare.
 *
 * @return {The return value for each of these functions indicates the ordinal relation of str1, str2.
 * 
 * < 0 str1 is less than str2
 *   0 str1 is identical to str2
 * > 0 str1 is greater than str2}
 */
int str_cmp(const char *str1, const char *str2);

/**
 * @ingroup string
 *
 * @brief Appends a string.
 *
 * @param buf Null-terminated destination string.
 * @param ch  Null-terminated source string.
 *
 * @return destination is returned.
 */
char *str_cat(char *dest, const char *src);

/**
 * @ingroup string
 *
 * @brief Gets the length of a string.
 *
 * @param str Null-terminated string.
 *
 * @return length of a string.
 */
size_t str_len(const char *str);

/**
 * @ingroup string
 *
 * @brief Copies a string.
 *
 * @param dest Destination string.
 * @param src  Null-terminated source string.
 *
 * @return destination is returned.
 */
char *str_cpy(char *dest, const char *src);

/**
 * @ingroup string
 *
 * @brief Copies the first num characters of source to destination.
 *
 *
 * @param dest Destination string.
 * @param src  Null-terminated source string.
 * @param num  Maximum number of characters to be copied from source. size_t is an unsigned integral type.
 *
 * @return destination is returned.
 */
char *str_cpyn(char *dest, const char *src, size_t num);

/**
 * @ingroup string
 *
 * @brief Returns the length of the initial portion of str1 which consists only of characters that are part of accept.
 *
 * @param str Null-terminated string.
 * @param accept Null-terminated string containing the characters to match.
 *
 * @return The length of the initial portion of str1 containing only characters that appear in accept. size_t is an unsigned integral type.
 */
size_t str_spn(const char *str, char *accept);

/**
 * @ingroup string
 *
 * @brief Scans str1 for the first occurrence of any of the characters that are part of str2, returning the number of characters of str1 read before this first occurrence.
 *
 * @param str Null-terminated source string to be scanned.
 * @param not_accept Null-terminated source string containing the characters to match.
 *
 * @return The length of the initial part of str not containing any of the characters that are part of not_accept.
 */
size_t str_cspn(const char *str, char *not_accept);

/**
 * @ingroup string
 *
 * @brief Returns a pointer to the first occurrence of character in the C string str.
 *
 * @param str pointer to the object to fill.
 * @param ch  Character to be located. It is passed as its int promotion, but it is internally converted back to char for the comparison.
 *
 * @return A pointer to the first occurrence of character in str.
 */
char *str_ch(char *str, char ch);

#endif //IMPLEMENTING_LIBC_STRING_H
