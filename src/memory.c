#include "memory.h"

/*
 * ===================================================================
 *                          MEMORY
 * ===================================================================
 * |                                                                 |
 * start                                                              end
 */
static short is_init = 0; ///< 1 if memory manager init else 0
static void *first = NULL; ///< first free byte of memory
static void *last = NULL; ///< last free byte of memory

static void init_memory_manager();

void *simple_calloc(unsigned long num, unsigned long size) {
  unsigned long total = num*size;
  void *result = simple_malloc(total);
  if (result)
    str_memset(result, '\0', total);
  return result;
}

void *simple_realoc(void *ptr, unsigned long size) {
  if (ptr) {
    void *result = simple_malloc(size);
    if (result)
      str_memcpy(result, ptr, size);
    return result;
  }
  return NULL;
}

void *simple_malloc(unsigned long size) {
  if (!is_init)
    init_memory_manager();

  if (size) {
    size = size + sizeof(mcb);

    void *result_memory_block = NULL;
    void *current_memory_block = first;
    mcb *current_mcb = NULL;

    while (current_memory_block!=last) {
      current_mcb = (mcb *) current_memory_block;

      /// if block is free and size is good -> get current block
      if (current_mcb->is_available) {
        if (current_mcb->size >= size) {
          current_mcb->is_available = 0;
          result_memory_block = current_memory_block;
          break;
        }
      }
      current_memory_block = (char *) current_memory_block + current_mcb->size;
    }
    ///allocate first or no available memory
    if (!result_memory_block) {
      ///get memory from os
      sbrk((intptr_t) size);

      result_memory_block = last;

      last = (char *) last + size;

      current_mcb = result_memory_block;
      current_mcb->is_available = 0;
      current_mcb->size = size;

      result_memory_block = (char *) result_memory_block + sizeof(mcb);
    }
    return result_memory_block;
  }
  return NULL;
}

static void init_memory_manager() {
  is_init = 1;
  last = sbrk(0);
  first = last;
}

void simple_free(void *ptr) {
  mcb *current_mcb = (void *) ((char *) ptr - sizeof(mcb));
  current_mcb->is_available = 1;
}
