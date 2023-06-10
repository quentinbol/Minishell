/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
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
#include <errno.h>

void if_not_executable(char **buffer, char **env, data_t *data, char *str2)
{
    if (execve(data->path, buffer, env) == -1) {
        if (errno == ENOEXEC) {
            my_printf("%s: Exec format error. ", buffer[0]);
            my_printf("Wrong Architecture.\n");
            exit(1);
        }
        command_not_found(buffer, str2, env, data);
    }
}

void check_access_commands(char **buffer, char **env, data_t *data, char *str2)
{
    if (buffer[0][0] == '.') {
        command_not_found(buffer, str2, env, data);
    }
    if (buffer[0][0] == '/') {
        if (execve(buffer[0], buffer, env) == -1);
            command_not_found(buffer, str2, env, data);
        return;
    }
    execve(data->path, buffer, env);
    if_not_executable(buffer, env, data, str2);
}

void cat_word(data_t *data, char **buffer, char **parc2)
{
    int count_found = 0;
    char *slash = "/";
    char *test_all = NULL;
    for (int i = 0; parc2[i]; i++) {
        my_strcat(parc2[i], slash);
        test_all = my_strcat(parc2[i], buffer[0]);
        if (access(test_all, F_OK) == 0) {
            data->path = test_all;
        }
    }
}

void return_status(char **buffer, int returnStatus, data_t *data)
{
    if (returnStatus == 256) {
        if (my_strcmp(buffer[0], "setenv") != 0
        && my_strcmp(buffer[0], "unsetenv") != 0
        && my_strcmp(buffer[0], "env") != 0)
            data->status = 1;
    } else {
        data->status = 0;
    }
}

int ls_handle(char **buffer, char **env, data_t *data, char *str2)
{
    int returnStatus, child_pid, pid;
    char *clear = NULL;
    char **parc = NULL;
    char **parc2 = NULL;
    for (int i = 0; env[i]; i++) {
        parc = my_str_to_word_array_2(env[i]);
        if (my_strcmp(parc[0], "PATH") == 0) {
            parc2 = my_str_to_word_array_gen(parc[1], ':');
            cat_word(data, buffer, parc2);
        }
    }
    pid = getpid();
    child_pid = fork();
    if (child_pid == 0) {
        check_access_commands(buffer, env, data, str2);
    }
    waitpid(child_pid, &returnStatus, 0);
    return_status(buffer, returnStatus, data);
    data->path = clear;
    return 1;
}
