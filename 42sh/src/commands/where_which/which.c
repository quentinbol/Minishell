/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** which.c
*/

#include "minishell.h"

static bool search_which(char *cmd_path, char *dir, char *cmd, int *stop)
{
    strcpy(cmd_path, dir);
    strcat(cmd_path, "/");
    strcat(cmd_path, cmd);
    if (builtin_or_not(cmd) && *stop == 0) {
        *stop = 1;
        printf("%s: shell built-in command.\n", cmd);
        return true;
    }
    if (access(cmd_path, F_OK | X_OK) == 0 && *stop == 0) {
        printf("%s\n", cmd_path);
        return true;
    }
    return false;
}

void which(mysh_t *mysh, char* cmd)
{
    char *path = get_env("PATH", mysh->env);
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char cmd_path[PATH_MAX];
    int stop = 0;
    bool found_path = false;

    if (cmd == NULL || strcmp(cmd, "") == 0) {
        printf("which: Too few arguments.\n");
        return;
    }
    while (dir != NULL && !found_path) {
        found_path = search_which(cmd_path, dir, cmd, &stop);
        dir = strtok(NULL, ":");
    }
    free(path_copy);
}
