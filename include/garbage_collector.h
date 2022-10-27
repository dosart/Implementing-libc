/*!
@file
@defgroup memory_management
@brief  Header file for simple garbage collector
It's a simple implementation of garbage collector.
Garbage collector based on mark and sweep algorithm(https://wiki.c2.com/?MarkAndSweep).
*/
#ifndef IMPLEMENTING_LIBC_INCLUDE_GARBAGE_COLLECTOR_H_
#define IMPLEMENTING_LIBC_INCLUDE_GARBAGE_COLLECTOR_H_

#include "memory.h"

#include <stdio.h>
#include <assert.h>

#define STACK_MAX 256

/*!
 * @ingroup memory_management
 *
 * @brief Garbage collector.
 *
 * The garbage collector treats memory as a directed reachability graph.
 * The graph nodes are divided into a set of root nodes and a set of dynamic memory nodes.
 * Each dynamic memory node corresponds to an allocated dynamic memory block. A directed edge p → q means that some cell in block p refers to some cell in block q.
 * Root nodes correspond to cells outside of the heap that refer to cells in the heap.
 * Such cells can be registers, variables on the stack, or global variables in the data segment in virtual memory.
 *
 */
typedef struct __vm_t
{
    mcb_t *stack[STACK_MAX];
    size_t stack_size;

} vm_t;

vm_t *make_vm();

/**
 * @ingroup memory_management
 *
 * @brief Add value to stack of garbage collector.
 *
 * @param gc Garbage collector.
 * @param value Value to add.
 */
void gc_push(vm_t *vm, mcb_t *mcb);

void gc_push_object(vm_t *vm, void *object);

void gc_push_int(vm_t *vm, int value);

mcb_t *gc_pop(vm_t *vm);

void gc_mark(mcb_t *mcb);

void gc_sweep();

void gc_mark_all(vm_t *vm);

#endif