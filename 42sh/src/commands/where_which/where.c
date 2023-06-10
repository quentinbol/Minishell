/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** where
*/

#include "minishell.h"

static void search_where(char *cmd_path, char *dir, char *cmd, int *stop)
{
    strcpy(cmd_path, dir);
    strcat(cmd_path, "/");
    strcat(cmd_path, cmd);
    if (builtin_or_not(cmd) && *stop == 0) {
        *stop = 1;
        printf("%s is a shell built-in\n", cmd);
    }
    if (access(cmd_path, F_OK | X_OK) == 0) {
        printf("%s\n", cmd_path);
    }
}

void where(mysh_t *mysh, char* cmd)
{
    char* path = get_env("PATH", mysh->env);
    char* path_copy = strdup(path);
    char* dir = strtok(path_copy, ":");
    char cmd_path[PATH_MAX];
    int stop = 0;

    if (cmd == NULL || strcmp(cmd, "") == 0) {
        printf("where: Too few arguments.\n");
        return;
    }
    while (dir != NULL) {
        search_where(cmd_path, dir, cmd, &stop);
        dir = strtok(NULL, ":");
    }
    free(path_copy);
}
