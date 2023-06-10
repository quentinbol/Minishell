/*
** EPITECH PROJECT, 2023
** Utils
** File description:
** Utils for MINISHELL
*/

#include "minishell.h"

int file_exists(char *path)
{
    if (access(path, F_OK) == 0)
        return (1);
    return (0);
}

int file_is_executable(char *path)
{
    if (access(path, X_OK) == 0)
        return (1);
    return (0);
}

int is_directory(char *path)
{
    struct stat finfo;

    stat(path, &finfo);
    return S_ISDIR(finfo.st_mode);
}
