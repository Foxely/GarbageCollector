/*
** EPITECH PROJECT, 2020
** list_getnode_at
** File description:
** get the node on the index we given in params
*/

#include <stdlib.h>
#include "generic_list.h"

node_t *list_get_first_node_with_value(list_t *p_list, void *p_value,
                                        value_comparator_t val_comp)
{
    if (!p_value || !val_comp)
        return 0;
    for (node_t *p_tmp = p_list->p_head; p_tmp; p_tmp = p_tmp->next) {
        if (!(*val_comp)(p_tmp->value, p_value))
            return p_tmp;
    }
    return NULL;
}

void list_clear_call(list_t *p_list, value_destroyer_t dtor)
{
    if (list_is_empty(p_list))
        return;
    node_t *p_delete = 0;
    node_t *p_tmp = p_list->p_head;

    while (p_tmp != NULL) {
        p_delete = p_tmp;
        p_tmp = p_tmp->next;
        dtor(p_delete->value);
        FREE(p_delete);
    }
}