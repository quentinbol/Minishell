/*
** EPITECH PROJECT, 2023
** replace_aliases
** File description:
** replaces the aliases by the new command
*/

#include "minishell.h"

int is_alias(mysh_t *mysh, char *cmd)
{
    node_t *node = mysh->alias->head;

    for (int i = 0; node != NULL; i++) {
        if (my_strcmp(cmd, node->alias) == 0)
            return i;
        node = node->next;
    }
    return -1;
}

char **end_copy(char **new_cmd, char **cmd, char **split_replace, int copy_pos)
{
    new_cmd[copy_pos] = NULL;
    free_array(cmd);
    free_array(split_replace);
    return new_cmd;
}

char **modify_cmd(char **cmd, char *replace, int pos_rep)
{
    int cmd_pos = 0;
    int copy_pos = 0;
    char **split_replace = buffer_to_word_array(replace, ' ');
    int len = len_array(cmd) + len_array(split_replace) - 1;
    char **new_cmd = malloc(sizeof(char *) * len + sizeof(NULL) * 1);

    for (; copy_pos != pos_rep; copy_pos++) {
        new_cmd[copy_pos] = my_strdup(cmd[cmd_pos]);
        cmd_pos++;
    }
    cmd_pos++;
    for (int i = 0; split_replace[i] != NULL; i++) {
        new_cmd[copy_pos] = my_strdup(split_replace[i]);
        copy_pos++;
    }
    for (; copy_pos <= (len - 1); copy_pos++) {
        new_cmd[copy_pos] = my_strdup(cmd[cmd_pos]);
        cmd_pos++;
    }
    return end_copy(new_cmd, cmd, split_replace, copy_pos);
}

char **replace_loop(mysh_t *mysh, char **cmd, int pos)
{
    int alias_exist = is_alias(mysh, cmd[pos]);

    while (alias_exist != -1) {
        cmd = modify_cmd(cmd, get_alias(mysh->alias, is_alias(mysh, cmd[pos])),
        pos);
        alias_exist = is_alias(mysh, cmd[pos]);
    }
    return cmd;
}

char **replace_aliases(mysh_t *mysh, char **cmd)
{
    for (int i = 0; cmd[i] != NULL; i++) {
        cmd = replace_loop(mysh, cmd, i);
    }
    return cmd;
}
