/*
** EPITECH PROJECT, 2023
** alias
** File description:
** handles the alias command
*/

#include "minishell.h"

static int size_of_array(char **array)
{
    int size = 0;

    for (; array[size] != NULL; size++);
    return size;
}

static void display_aliases(mysh_t *mysh)
{
    node_t *node = mysh->alias->head;

    while (node != NULL) {
        my_printf("%s\t%s\n", node->alias, node->replace);
        node = node->next;
    }
    return;
}

static void modify_alias(alias_t *list, int node_num, char **cmd)
{
    node_t *node = list->head;

    for (int i = 0; i != node_num; i++) {
        node = node->next;
    }
    free(node->replace);
    node->replace = concat_rep(cmd);
    return;
}

void alias(mysh_t *mysh, char **cmd)
{
    int exists = -1;

    if (size_of_array(cmd) == 1)
        return display_aliases(mysh);
    exists = is_alias(mysh, cmd[1]);
    if (size_of_array(cmd) > 2 && exists == -1)
        add_alias(mysh->alias, my_strdup(cmd[1]), concat_rep(cmd));
    if (size_of_array(cmd) > 2 && exists != -1)
        modify_alias(mysh->alias, exists, cmd);
    if (size_of_array(cmd) == 2 && exists != -1)
        my_printf("%s\n", get_alias(mysh->alias, exists));
    return;
}
