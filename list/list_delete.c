/*
** EPITECH PROJECT, 2020
** list_delete
** File description:
** Delete a node
*/

#include <stdlib.h>
#include "generic_list.h"

bool list_del_elem_at_front(list_t *p_list)
{
    if (list_is_empty(p_list))
        return false;

    node_t *p_delete = p_list->p_head;
    p_list->p_head = p_delete->next;
    if (p_list->dtor)
        p_list->dtor(p_delete->value);
    FREE(p_delete);
    p_list->u_size--;
    return true;
}

bool list_del_elem_at_back(list_t *p_list)
{
    if (list_is_empty(p_list))
        return false;

    node_t *p_prev = NULL;
    node_t *p_tmp = p_list->p_head;
    while (p_tmp->next->next != NULL) {
        p_tmp = p_tmp->next;
    }
    p_prev = p_tmp;
    p_tmp = p_tmp->next;

    node_t *p_delete = p_tmp;
    p_prev->next = NULL;
    if (p_list->dtor)
        p_list->dtor(p_delete->value);
    FREE(p_delete);
    p_list->u_size--;
    return true;
}

bool list_del_elem_at_position(list_t *p_list, unsigned int u_position)
{
    if (u_position == 0)
        return list_del_elem_at_front(p_list);
    if (list_is_empty(p_list) ||
        u_position > list_get_size(p_list) - 1)
        return false;

    node_t *p_delete = 0;
    unsigned int i = 0;
    for (node_t *p_tmp = p_list->p_head, *p_prev = NULL;
            p_tmp != NULL; p_prev = p_tmp, p_tmp = p_tmp->next, ++i)
        if (i == u_position) {
            p_delete = p_tmp;
            p_prev->next = p_delete->next;
            break;
        }
    if (p_list->dtor)
        p_list->dtor(p_delete->value);
    FREE(p_delete);
    p_list->u_size--;
    return true;
}

bool list_del_node(list_t *p_list, node_t *p_node)
{
    unsigned int i = 0;
    for (node_t *p_tmp = p_list->p_head; p_tmp; p_tmp = p_tmp->next, ++i) {
        if (p_tmp == p_node) {
            list_del_elem_at_position(p_list, i);
            return true;
        }
    }
    return false;
}