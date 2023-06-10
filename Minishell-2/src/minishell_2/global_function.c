/*
** EPITECH PROJECT, 2023
** gloabk
** File description:
** func
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../../lib/my/prototypes.h"
#include "../../include/my.h"

void exec_t(char **args, char *str2, data_t *data)
{
    if (data->path != NULL) {
        if (execve(data->path, args, NULL) == -1) {
            command_not_found_2(args, str2, data);
        }
    }
}

void all_combine(char **pipe_buff, char **pars_env2, data_t *data, int k)
{
    int count_find = 0;
    char *slash = "/";
    char **final_buffer = NULL;
    char *final = NULL;
    for (int i = 0; pars_env2[i]; i++) {
        my_strcat(pars_env2[i], slash);
        final_buffer = my_str_to_word_array_gen_2(pipe_buff[k], ' ', '\t');
        final = my_strcat(pars_env2[i], final_buffer[0]);
        if (access(final, F_OK) == 0) {
            data->path = final;
            count_find = 1;
        }
    }
    if (count_find == 0) {
        data->path = pipe_buff[data->i];
    }
}

void find_path(char **pipe_buff,char **env, data_t *data, int k)
{
    char *final = NULL;
    char **pars_env = NULL;
    char **pars_env2 = NULL;

    for (int i = 0; env[i]; i++) {
        pars_env = my_str_to_word_array_2(env[i]);
        if (my_strcmp(pars_env[0], "PATH") == 0) {
            pars_env2 = my_str_to_word_array_gen(pars_env[1], ':');
            all_combine(pipe_buff, pars_env2, data, k);
        }
    }
}
