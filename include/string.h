/*!
@file
@brief  Header file for string
This file contains functions implementation from libs (string.h)
*/
#ifndef IMPLEMENTING_LIBC_STRING_H
#define IMPLEMENTING_LIBC_STRING_H

#include <stddef.h>

/**
 * @ingroup string
 *
 * @brief copies n bytes from memory area src to
 *     memory area dest
 *
 * The str_memcpy() function copies n bytes from memory area src to
 *     memory area dest.  The memory areas must not overlap.  Use
 *      memmove(3) if the memory areas do overlap.
 *
 * @param dest destination area
 * @param src source area
 * @param n, bytes count

 * @returns a pointer to dest.
 */
void *str_memcpy(void *dest, const void *src, size_t n);

void *str_memset(void *buf, char z, size_t);

int str_cmp(const char *str1, const char *str2);

char *str_cat(char *destptr, const char *srcptr);

size_t str_len(const char *str);

char *str_cpy(char *dest, const char *src);

char *str_cpyn(char *dest, const char *src, size_t n);

size_t str_spn(const char *str, char *accept);

char *str_ch(char *str, char c);
#endif //IMPLEMENTING_LIBC_STRING_H
