/*
** EPITECH PROJECT, 2023
** separator handling
** File description:
** separator
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../../lib/my/prototypes.h"
#include "../../include/my.h"
#include "../../lib/my/prototypes.h"

void if_wait(data_t *data, int count)
{
    for (int i = 0; i < count; i++) {
        wait(NULL);
    }
}

void check_arguments(char **env, data_t *data, char *str2)
{
    if (my_strcmp(data->args[0], "cd") == 0) {
        cd_handle(data->args, env, data);
        data->status = 5;
    }
    if (my_strcmp(data->args[0], "exit") == 0) {
        exit_shell(data->args, env, str2, data);
        data->status = 5;
        }
    if (my_strcmp(data->args[0], "setenv") == 0) {
        env = check_env(data->args, env, data, str2);
        data->status = 5;
    }
    if (my_strcmp(data->args[0], "unsetenv") == 0) {
        check_unsetenv(data->args, env, data);
        data->status = 5;
    }
    if (my_strcmp(data->args[0], "env") == 0) {
        print_env(env);
        data->status = 5;
    }
}

void check_binairy(data_t *data, char *str2)
{
    int pid;
    int status;
    if (data->status != 5) {
        pid = fork();
        if (pid == 0 && data->status != 5) {
            exec_t(data->args, str2, data);
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void execute_commands(char **pipe_buff, data_t *data, char **env, char *str2)
{
    for (int j = 0; pipe_buff[data->i][j]; j++) {
        if (pipe_buff[data->i][j] == '|')
            data->count = 1;
        if (pipe_buff[data->i][j] == '>') {
            double_redirect(pipe_buff, data, j);
            data->count = 2;
        }
    }
    if (data->count == 0) {
        data->status = 0;
        data->args = my_str_to_word_array_gen_2(pipe_buff[data->i], ' ', '\t');
        if (pipe_buff[data->i][0] != '/') {
            find_path(pipe_buff, env, data, data->i);
        }
        check_arguments(env, data, str2);
        check_binairy(data, str2);
    }
}

void separator_handling(char** pipe_buff, char **env, data_t *data, char *str2)
{
    data->count = 0;
    data->args = NULL;
    for (data->i = 0; pipe_buff[data->i]; data->i++) {
        data->count = 0;
        execute_commands(pipe_buff, data, env, str2);
        if (data->count == 1) {
            pipe_handling(pipe_buff[data->i], env, data, str2);
        }
        if (data->count == 2) {
            redirection_handling_2(pipe_buff[data->i], data, env, str2);
        }
    }
}
