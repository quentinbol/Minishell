/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** pars
*/

#include "../../lib/my/prototypes.h"
#include "../../include/my.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

void redirection_parsing(char **parsing, data_t *data, char **env, char *str2)
{
    parsing = my_str_to_word_array_gen_2(str2, '>', '=');
    for (data->b = 0; parsing[data->b]; data->b++) {
        parsing[data->b] = clean_string(parsing[data->b]);
        data->number++;
    }
    redirection_handling(parsing, data, env , str2);
    data->handled = 3;
}

void pipe_parsing(char **parsing, data_t *data, char **env, char *str2)
{
    parsing = my_str_to_word_array_gen_2(str2, '|', '=');
    for (data->b = 0; parsing[data->b]; data->b++) {
        parsing[data->b] = clean_string(parsing[data->b]);
    }
    pipe_handling_2(parsing, env, data, str2);
    data->handled = 3;
}

void parsing_separator_pipe(char **parsing, char *str2, data_t *data
                            , char **env)
{
    if (data->c == 0 && data->m == 1) {
        pipe_parsing(parsing, data, env, str2);
        return;
    }
    if (data->handled == 3) {
        for (int i = 0; parsing[i]; i++) {
            parsing[i] = clean_string(parsing[i]);
        }
        separator_handling(parsing, env, data, str2);
    }
    if (data->c == 0 && data->m == 2) {
        redirection_parsing(parsing, data, env, str2);
    }
}

void if_redirection(char *str2, data_t *data, int i)
{
    if (str2[i] == '>') {
        if (str2[i + 1] == '>')
            data->double_red = 1;
        data->m = 2;
    }
}

void minishell_2(char **buffer, char **env, char *str2, data_t *data)
{
    char **parsing = NULL;
    char **parsing_2;
    data->c = 0;
    data->m = 0;
    data->double_red = 0;

    for (int i = 0; str2[i]; (i)++) {
        if (str2[i] == ';') {
        data->c = 1;
        data->handled = 3;
        parsing = my_str_to_word_array_gen_2(str2, ';', '=');
        }
        if (str2[i] == '|')
            data->m = 1;
        if_redirection(str2, data, i);
    }
    parsing_separator_pipe(parsing, str2, data, env);
}
