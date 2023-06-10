/*
** EPITECH PROJECT, 2023
** alias_list
** File description:
** functions to handles alias list
*/

#include "aliases.h"

alias_t *list_create(void)
{
    alias_t *list = malloc(sizeof(alias_t));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

static unsigned int add_node(alias_t *list, node_t *node)
{
    list->size++;
    node->next = NULL;
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
        return 0;
    }
    list->tail->next = node;
    list->tail = node;
    return (list->size - 1);
}

unsigned int add_alias(alias_t *list, char *value, char *replacement)
{
    node_t *node;

    if (list == NULL || value == NULL || replacement == NULL) {
        write(1, "list_add : list of value is NULL\n", 33);
        return 0;
    }
    node = malloc(sizeof(node_t));
    node->alias = value;
    node->replace = replacement;
    node->next = NULL;
    return add_node(list, node);
}

char *get_alias(alias_t *list, unsigned int index)
{
    node_t *node;
    unsigned int current = 0;

    if (list == NULL) {
        write(1, "list_get_node : list == NULL\n", 29);
        return NULL;
    }
    node = list->head;
    if (node == NULL) {
        write(1, "list_get_node : node == NULL\n", 29);
        return NULL;
    }
    while (node != NULL && current < index) {
        current++;
        node = node->next;
    }
    if (node != NULL)
        return node->replace;
    return NULL;
}
