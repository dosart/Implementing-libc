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
    mcb_t *stack[STACK_MAX]; ///< Stack for root nodes
    size_t stack_size;

} vm_t;

/**
 * @ingroup memory_management
 *
 * @brief Create a new VM and push the pointer to its own stack.
 *
 * @returns Pointer to virtual machine
 */
vm_t *make_vm();

/**
 * @ingroup memory_management
 *
 * @brief Add mcb(memory control block) to stack.
 *
 * @param vm Virtual machine of garbage collector.
 * @param mcb Mcb to add. Must be received after calling the simple_malloc function(memory.h).
 */
void gc_push(vm_t *vm, mcb_t *mcb);

/**
 * @ingroup memory_management
 *
 * @brief Add object to stack.
 *
 * @param vm Virtual machine of garbage collector.
 * @param object to add. Must be received after calling the simple_malloc function(memory.h).
 */
void gc_push_object(vm_t *vm, void *object);

/**
 * @ingroup memory_management
 *
 * @brief Allocate new memory of size sizeof(int) and add int to stack.
 *
 * @param vm Virtual machine of garbage collector.
 * @param int to add.
 */
void gc_push_int(vm_t *vm, int value);

/**
 * @ingroup memory_management
 *
 * @brief Extract value from the stack of virtual machine.
 *
 * @param vm Virtual machine of garbage collector.
 *
 * @returns Pointer to extracted objecte.
 */
mcb_t *gc_pop(vm_t *vm);

/**
 * @ingroup memory_management
 *
 * @brief Marking stage. Mark all objects in scope(in stack)
 *
 * @param vm Virtual machine of garbage collector(contains stack).
 */
void gc_mark_all(vm_t *vm);

/**
 * @ingroup memory_management
 *
 * @brief Marking stage. Mark objects in scope(in stack)
 *
 * @param mcb mcb to mark.
 */
void gc_mark(mcb_t *mcb);

/**
 * @ingroup memory_management
 *
 * @brief Cleaning stage. Remove objects not in scope(not marked). Remove object in heap.
 *
 * @param mcb mcb to mark.
 */
void gc_sweep();

#endif
