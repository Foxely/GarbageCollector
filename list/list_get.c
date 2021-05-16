/*
** EPITECH PROJECT, 2020
** list_get
** File description:
** get the data with the index we given
*/

#include <stdlib.h>
#include "generic_list.h"

void *list_get_elem_at_front(list_t *p_list)
{
    if (list_is_empty(p_list))
        return 0;
    return p_list->p_head->value;
}

void *list_get_elem_at_back(list_t *p_list)
{
    if (list_is_empty(p_list))
        return 0;
    return p_list->p_tail->value;
}

void *list_get_elem_at_position(list_t *p_list, unsigned int u_position)
{
    if (u_position == 0)
        return list_get_elem_at_front(p_list);
    if (list_is_empty(p_list) ||
        u_position > list_get_size(p_list) - 1)
        return 0;
    node_t *p_tmp = p_list->p_head;
    for (unsigned int i = 0; i < u_position; ++i) {
        p_tmp = p_tmp->next;
    }
    return p_tmp->value;
}