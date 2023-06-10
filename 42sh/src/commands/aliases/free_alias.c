/*
** EPITECH PROJECT, 2023
** free_alias
** File description:
** frees the alias list at the end of the program
*/

#include "minishell.h"

static void remove_node(alias_t *list, node_t *node)
{
    list->size--;
    if (list->head == node)
        list->head = node->next;
    node->next = NULL;
    free(node);
}

void remove_alias(alias_t *list)
{
    node_t *node;

    if (list == NULL) {
        write(1, "list_remove : list == NULL\n", 27);
        return;
    }
    node = list->head;
    if (node != NULL) {
        remove_node(list, node);
    }
}

void free_alias(alias_t *list)
{
    node_t *node = list->head;

    while (node != NULL) {
        free(node->alias);
        free(node->replace);
        remove_alias(list);
        node = list->head;
    }
    free(list);
    return;
}
