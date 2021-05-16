/*
** EPITECH PROJECT, 2019
** gc_stop
** File description:
** stop the GC
*/

#include "garbage.h"

void free_object(void *p_obj)
{
    object_t *p_object = (object_t *) p_obj;
    free(p_object);
}

void gc_stop(gc_t *vm)
{
    vm->stack_size = 0;
    gc_run(vm);
    list_clear_call(&vm->v_free, &free_object);
    free(vm);
}