/*
** EPITECH PROJECT, 2020
** my_list_size
** File description:
** Func that returns the number of elemnts onthe list
*/

#include <stdlib.h>
#include <stdio.h>
#include "generic_list.h"

unsigned int list_get_size(list_t *p_list)
{
    return (p_list->u_size);
}

bool list_is_empty(list_t *p_list)
{
    return p_list->p_head == NULL || p_list->u_size <= 0;
}

void list_clear(list_t *p_list)
{
    if (p_list->dtor) {
        list_clear_call(p_list, p_list->dtor);
        return;
    }
    if (list_is_empty(p_list))
        return;
    node_t *p_delete = 0;
    node_t *p_tmp = p_list->p_head;

    while (p_tmp != NULL) {
        p_delete = p_tmp;
        p_tmp = p_tmp->next;
        FREE(p_delete);
    }
}

void list_dump(list_t *p_list, value_displayer_t printer)
{
    if (list_is_empty(p_list) || !printer)
        return;
    node_t *p_tmp = p_list->p_head;
    while (p_tmp != NULL) {
        printer(p_tmp->value);
        p_tmp = p_tmp->next;
    }
}

node_t *list_create_node(void *p_elem)
{
    node_t *p_element = 0;
    #ifdef __cplusplus
        p_element = new(node_t);
    #else
        p_element = malloc(sizeof(node_t));
    #endif
    if (!p_element)
        return 0;

    p_element->value = p_elem;
    p_element->next = 0;
    return p_element;
}