/*
** EPITECH PROJECT, 2023
** Get env
** File description:
** Get elements of ENV
*/

#include "minishell.h"

int str_start_with(char *str, char *elem)
{
    if (my_strlen(str) < my_strlen(elem))
        return (0);
    for (int i = 0; elem[i] != '\0'; i++) {
        if (str[i] != elem[i])
            return (0);
    }
    return (1);
}

static int find_index_equal_sign(char *str)
{
    int i = 0;

    for (; str[i] != '=' && str[i] != '\0'; i++);
    return (i + 1);
}

int check_env(char *var_name, char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(var_name, env[i], len_str(var_name)) == 0)
            return (1);
    }
    return (0);
}

char *get_env(char *name, char **env)
{
    char *value = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        if (str_start_with(env[i], name))
            value = my_strdup(&env[i][find_index_equal_sign(env[i])]);
    }
    return (value);
}
