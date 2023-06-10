/*
** EPITECH PROJECT, 2023
** pipe
** File description:
** handling
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../../lib/my/prototypes.h"
#include "../../include/my.h"

void if_slash(char **pipe_buff, int i, char **env, data_t *data)
{
    if (pipe_buff[i][0] != '/') {
        find_path(pipe_buff, env, data, i);
    }
}

void if_enter_child(int i, int fd_in, int *fd, int count)
{
    if (i != 0) {
        dup2(fd_in, STDIN_FILENO);
    }
    if (i != count - 1) {
        dup2(fd[1], STDOUT_FILENO);
    }
}

void clean_my_string(char **buffer, data_t *data)
{
    for (int i = 0; buffer[i]; i++) {
        data->count2++;
        clean_string(buffer[i]);
    }
}

void pipe_handling(char* pipe_buff, char **env, data_t *data, char *str2)
{
    data->count2 = 0; int fd[2]; pid_t pid; char **args; int i = 0;
    int fd_in = STDIN_FILENO;
    char **buffer = my_str_to_word_array_gen(pipe_buff, '|');
    clean_my_string(buffer, data);
    for (int i = 0; i < data->count2; i++) {
        args = my_str_to_word_array_gen(buffer[i], ' ');
        pipe(fd);
        pid = fork();
        data->path = args[0];
        if (pid == 0) {
            if_enter_child(i, fd_in, fd, data->count2);
            if_slash(buffer, i, env, data);
            exec_t(args, str2, data);
        } else
            close(fd[1]);
            fd_in = fd[0];
    }
    if_wait(data, data->count2);
}

void pipe_handling_2(char** pipe_buff, char **env, data_t *data, char *str2)
{
    int fd[2];
    pid_t pid;
    char **args;
    int i = 0;
    int fd_in = STDIN_FILENO;
    for (int i = 0; i < data->b; i++) {
        args = my_str_to_word_array_gen(pipe_buff[i], ' ');
        pipe(fd);
        pid = fork();
        data->path = args[0];
        if (pid == 0) {
            if_enter_child(i, fd_in, fd, data->b);
            if_slash(pipe_buff, i, env, data);
            exec_t(args, str2, data);
        } else
            close(fd[1]);
            fd_in = fd[0];
    }
    if_wait(data, data->b);
}
