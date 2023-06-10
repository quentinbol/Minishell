/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "../lib/my/prototypes.h"
#include "../include/my.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>


void static build_in_bis(char **buffer, char **env, char *str2, data_t *data)
{
    if (executable_handle(buffer, env, data) != 1) {
        if (ls_handle(buffer, env, data, str2) != 1) {
            exit_shell(buffer, env, str2, data);
        }
    }
}

void static build_in(char **buffer, char **env, char *str2, data_t *data)
{
    if (cd_handle(buffer, env, data) != 1)
        if (pwd(buffer, data) != 1)
            build_in_bis(buffer, env, str2, data);
}

void static check_command(char **buffer, char **env, char *str2, data_t *data)
{
    if (environnement(buffer, env) != 1)
            build_in(buffer, env, str2, data);
    start_shell(env, data);
}

int start_shell(char **env, data_t *data)
{
    size_t nb = 0;
    char *str = NULL;
    char *str2 = NULL;
    char **buffer = NULL;
    char **final_copy = NULL;
    ssize_t read = 0;
    while (1) {
        if ((isatty(0)))
            my_printf("[mini_shell]$ ");
        read = getline(&str2, &nb, stdin);
        get_line_term(read, env, str2, data);
        if (str2[0] == '\n')
            start_shell(env, data);
        str = my_strdup_shell(str2);
        buffer = my_str_to_word_array(str);
        final_copy = check_env(buffer, env, data, str2);
        check_unsetenv(buffer, final_copy, data);
        exit_shell(buffer, env, str2, data);
        check_command(buffer, final_copy, str2, data);
    }
}
