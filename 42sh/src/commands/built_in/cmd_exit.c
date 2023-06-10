/*
** EPITECH PROJECT, 2023
** EXIT
** File description:
** exit cmd
*/

#include "minishell.h"

int cmd_exit(mysh_t *mysh, char **cmd)
{
    int len = len_array(cmd);
    int nb;

    mysh->is_launch = 0;
    if (len == 1)
        exit(0);
    if (len > 1) {
        nb = my_getnbr(cmd[1]);
        exit(nb);
    }
    return (0);
}
