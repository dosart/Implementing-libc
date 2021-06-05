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
void* str_memcpy(void* dest, const void* src, size_t n);

void* str_memset(void *buf, char z, size_t);

#endif //IMPLEMENTING_LIBC_STRING_H
