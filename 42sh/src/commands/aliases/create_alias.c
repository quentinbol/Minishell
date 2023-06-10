/*
** EPITECH PROJECT, 2023
** create_alias
** File description:
** contains the functions that copies the new alias and its replacements
*/

#include "minishell.h"

static int get_rep_len(int start, char **cmd)
{
    int len = 0;

    for (; cmd[start] != NULL; start++) {
        len += (my_strlen(cmd[start]) + 1);
    }
    return len;
}

static char *concat_param(char **cmd, char *replace, int i, int pos)
{
    for (int j = 0; cmd[i][j] != '\0'; j++) {
        replace[pos] = cmd[i][j];
        pos++;
    }
    if (cmd[i + 1] == NULL)
        replace[pos] = '\0';
    else
        replace[pos] = ' ';
    return replace;
}

char *concat_rep(char **cmd)
{
    char *replace = malloc(sizeof(char) * get_rep_len(2, cmd));
    int pos = 0;

    for (int i = 2; cmd[i] != NULL; i++) {
        replace = concat_param(cmd, replace, i, pos);
        pos += my_strlen(cmd[i]) + 1;
    }
    return replace;
}
