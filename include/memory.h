/*!
@file
@defgroup memory_management
@brief  Header file for malloc
This file contains functions implementation from libs (malloc.h)
*/
#ifndef IMPLEMENTING_LIBC_INCLUDE_MEMORY_H_
#define IMPLEMENTING_LIBC_INCLUDE_MEMORY_H_

#include "string.h"

#include <stddef.h>
#include <unistd.h>

/*!
 * @ingroup memory_management
 *
 * @brief Memory block characteristic
*/
typedef struct memory_control_block {
  unsigned long size; ///< Memory block size
  short is_available; ///< 1 is free else 0
} mcb;

/**
 * @ingroup memory_management
 *
 * @brief Allocates size bytes of uninitialized storage.
 *
 * @param size Number of bytes to allocate.
 *
 * @returns On success, returns the pointer to the beginning of newly allocated memory.
 */
void* simple_malloc(unsigned long size);

/**
 * @ingroup memory management
 *
 * @brief Deallocates the space previously allocated by malloc(), calloc(), realoc().
 *
 * @param ptr Pointer to the memory to deallocate.
 */
void simple_free(void *ptr);

/**
 * @ingroup memory_management
 *
 * @brief Allocates memory for an array of num objects of size size and initializes it to all bits zero.
 *
 * @param num Number of objects.
 * @param size Size of each object.
 *
 * @returns On success, returns the pointer to the beginning of newly allocated memory.
 */
void *simple_calloc(unsigned long num, unsigned long size);

/**
 * @ingroup memory_management
 *
 * @brief Reallocates the given area of memory.
 *
 * @param num Number of objects.
 * @param ptr Pointer to the memory area to be reallocated
 * @param new_size New size of the array in bytes.
 *
 * @returns On success, returns the pointer to the beginning of newly allocated memory.
 */
void *simple_realoc(void *ptr, unsigned long size);

#endif //IMPLEMENTING_LIBC_INCLUDE_MEMORY_H_
