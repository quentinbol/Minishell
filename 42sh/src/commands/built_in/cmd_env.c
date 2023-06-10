/*
** EPITECH PROJECT, 2023
** CMD Env
** File description:
** display env
*/

#include "minishell.h"

int cmd_env(mysh_t *mysh)
{
    for (int i = 0; mysh->env[i] != NULL; i++)
        my_printf("%s\n", mysh->env[i]);
    return (0);
}
