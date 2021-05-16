/*
** EPITECH PROJECT, 2019
** mark_sweep
** File description:
** sf
*/

#include <stdio.h>
#include <stdlib.h>
#include "garbage.h"

static inline gc_t *gc_static;

int assert(int condition, const char *message)
{
    if (!condition) {
        printf("%s\n", message);
        return (1);
    }
    return (0);
}

static size_t hash(void *ptr)
{
    return ((unsigned long)ptr) >> 3;
}

gc_t *get_garbage(void)
{
    return (gc_static);
}

gc_t *my_gc_new(void)
{
    if (gc_static != NULL)
        return (gc_static);
    gc_t *vm = malloc(sizeof(gc_t));
    vm->stack_size = 0;
    vm->first_object = NULL;
    vm->num_objects = 0;
    vm->max_objects = 8;
    list_init(&vm->v_free, 0);
    gc_static = vm;
    return (vm);
}

int search_first_size(void *data, void *p_size)
{
    size_t l_size_to_find = *(size_t *) p_size;
    object_t *p_obj = (object_t *) data;

    return 0;
}

object_t *new_object(gc_t *vm, object_type type, size_t size)
{
    if (vm->num_objects >= vm->max_objects)
        gc_run(vm);
    object_t *object = 0;
    node_t *p_found = list_get_first_node_with_value(&vm->v_free, &size, &search_first_size);
    if (p_found) {
        object = (object_t *) p_found->value;
        list_del_node(&vm->v_free, p_found);
    } else {
        object = malloc(sizeof(object_t) + size);
        printf("alloc\n");
    }
    object->type = type;
    object->next = vm->first_object;
    object->marked = 0;
    object->l_size = size;
    vm->first_object = object;
    vm->num_objects++;
    return (object);
}