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

void double_redirect(char **pipe_buff, data_t *data, int j)
{
    if (pipe_buff[data->i][j + 1] == '>')
        data->double_red = 1;
}

void static check_command(char **buffer, char **env, char *str2, data_t *data)
{
    data->handled = 0;
    minishell_2(buffer, env, str2, data);
    if (my_strcmp(buffer[0], "env") == 0 && data->handled != 3)
        data->handled = environnement(buffer, env);
    if (my_strcmp(buffer[0], "cd" ) == 0 && data->handled != 3)
        data->handled = cd_handle(buffer, env, data);
    if (!data->handled && data->handled != 3)
        data->handled = executable_handle(buffer, env, data);
    if (my_strcmp(buffer[0], "exit" ) == 0 && data->handled != 3) {
        exit_shell(buffer, env, str2, data);
    }
    if (!data->handled && data->opt != 1 && data->handled != 3) {
        data->handled = ls_handle(buffer, env, data, str2);
    }
    if (!data->handled)
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
        str = clean_string(str2);
        if (str[0] == '\0' || str2[0] == '\n' || my_strcmp(str2, ";") == 0) {
            start_shell(env, data);
        }
        buffer = my_str_to_word_array(str);
        env = check_env(buffer, env, data, str2);
        check_unsetenv(buffer, env, data);
        check_command(buffer, env, str2, data);
    }
}
