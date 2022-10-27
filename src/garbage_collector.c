#include "garbage_collector.h"
#include <assert.h>

vm_t *make_vm()
{
    vm_t *vm = (vm_t *)simple_malloc(sizeof(vm_t));
    if (vm == NULL)
        return NULL;
    gc_push(vm, (void *)vm);
    return vm;
}

void gc_push_int(vm_t *vm, int value)
{
    int *ptr = (int *)simple_malloc(sizeof(int));
    *ptr = value;
    gc_push_object(vm, (void *)ptr);
}

void gc_push_object(vm_t *vm, void *object)
{
    mcb_t *current_mcb = (mcb_t *)((char *)object - sizeof(mcb_t));
    current_mcb->marked = 0;
    gc_push(vm, current_mcb);
}

void gc_push(vm_t *vm, mcb_t *mcb)
{
    assert(vm->stack_size < STACK_MAX);
    vm->stack[vm->stack_size++] = mcb;
}

mcb_t *gc_pop(vm_t *vm)
{
    assert(vm->stack_size > 0);
    return vm->stack[--vm->stack_size];
}

void gc_sweep()
{
    void *current_memory_block = get_first_bite();
    void *last_memory_block = get_first_bite();
    mcb_t *current_mcb = NULL;

    while (current_memory_block != last_memory_block)
    {
        current_mcb = (mcb_t *)current_memory_block;
        if (current_mcb->marked == 0)
        {
            /* This object wasn't reached, so free it. */
            simple_free((void *)((char *)current_memory_block + sizeof(mcb_t)));
        }
        else
        {
            /* This object was reached, so unmark it (for the next GC) and move on to the next. */
            current_mcb->marked = 0;
        }
        current_memory_block = (char *)current_memory_block + current_mcb->size;
    }
}

void gc_mark_all(vm_t *vm)
{
    if (vm == NULL)
        return;

    for (size_t i = 0; i < vm->stack_size; i++)
    {
        gc_mark(vm->stack[i]);
    }
}

void gc_mark(mcb_t *mcb)
{
    if (mcb == NULL)
        return;

    mcb->marked = 1;
}
