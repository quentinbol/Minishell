/*
** EPITECH PROJECT, 2023
** CMd Built in
** File description:
** Minishell
*/

#include "minishell.h"

static int check_built_in_cmd3(mysh_t *mysh, char **cmd)
{
    if (my_strcmp(cmd[0], "alias") == 0) {
        alias(mysh, cmd);
        return (1);
    }
    return (0);
}

static int check_built_in_cmd2(mysh_t *mysh, char **cmd)
{
    if (my_strcmp(cmd[0], "setenv") == 0) {
        cmd_setenv(mysh, cmd);
        return (1);
    }
    if (my_strcmp(cmd[0], "unsetenv") == 0) {
        cmd_unsetenv(mysh, cmd);
        return (1);
    }
    if (my_strcmp(cmd[0], "where") == 0) {
        where(mysh, cmd[1]);
        return (1);
    }
    if (my_strcmp(cmd[0], "which") == 0) {
        which(mysh, cmd[1]);
        return (1);
    }
    if (check_built_in_cmd3(mysh, cmd))
        return (1);
    return (0);
}

int check_built_in_cmd(mysh_t *mysh, char **cmd)
{
    if (my_strcmp(cmd[0], "cd") == 0) {
        cmd_cd(mysh, cmd);
        return (1);
    }
    if (my_strcmp(cmd[0], "env") == 0) {
        cmd_env(mysh);
        return (1);
    }
    if (my_strcmp(cmd[0], "exit") == 0) {
        cmd_exit(mysh, cmd);
        return (1);
    }
    if (strcmp(cmd[0], "history") == 0 || mysh->histo__->command_not_found) {
        return (1);
    }
    if (check_built_in_cmd2(mysh, cmd))
        return (1);
    return (0);
}
