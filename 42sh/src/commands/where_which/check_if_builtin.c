/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** check if builtin
*/

#include "minishell.h"

bool builtin_or_not(char* cmd)
{
    if (strcmp(cmd, "cd") == 0 ||
        strcmp(cmd, "echo") == 0 ||
        strcmp(cmd, "exit") == 0 ||
        strcmp(cmd, "setenv") == 0 ||
        strcmp(cmd, "unsetenv") == 0) {
        return true;
    }
    return false;
}
