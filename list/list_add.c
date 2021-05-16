/*
** EPITECH PROJECT, 2020
** create_element
** File description:
** create a new element
*/

#include <stdlib.h>
#include <stdio.h>
#include "generic_list.h"

void list_init(list_t *p_list, value_destroyer_t dtor)
{
    p_list->dtor = dtor;
    p_list->p_head = 0;
    p_list->p_tail = 0;
    p_list->u_size = 0;
}

bool list_add_elem_at_front(list_t *p_list, void *p_elem)
{
    if (!p_elem)
        return false;
    node_t *p_element = list_create_node(p_elem);
    if (!p_element)
        return false;

    p_element->next = p_list->p_head;
    p_list->p_head = p_element;
    p_list->u_size++;
    return (true);
}

bool list_add_elem_at_back(list_t *p_list, void *p_elem)
{
    if (!p_elem)
        return false;
    if (list_is_empty(p_list))
        return list_add_elem_at_front(p_list, p_elem);
    node_t *p_tmp = p_list->p_head;
    while (p_tmp->next != NULL)
        p_tmp = p_tmp->next;

    node_t *p_element = list_create_node(p_elem);
    if (!p_element)
        return false;
    p_list->p_tail = p_tmp;
    p_tmp->next = p_element;
    p_list->u_size++;
    return (true);
}

bool list_add_elem_at_position(list_t *p_list, void *p_elem,
                                        unsigned int u_position)
{
    if (u_position == 0)
        return list_add_elem_at_front(p_list, p_elem);
    if (!p_elem || u_position > list_get_size(p_list))
        return false;

    unsigned int i = 0;
    node_t *p_tmp = p_list->p_head;
    while (p_tmp != NULL && i < u_position - 1) {
        ++i;
        p_tmp = p_tmp->next;
    }
    node_t *p_element = list_create_node(p_elem);
    if (!p_element)
        return false;
    p_element->next = p_tmp->next;
    p_tmp->next = p_element;
    p_list->u_size++;
    return (true);
}