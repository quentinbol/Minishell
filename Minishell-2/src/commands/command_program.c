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
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

void if_child_exist(int child_pid, char **buffer, char **env)
{
    if (child_pid == 0) {
        if (execve(buffer[0], buffer, env) == -1)
            if_wrong_architecture(buffer);
        exit(1);
    }
}

int if_cant_execute(char **buffer, data_t *data)
{
    if (access(buffer[0], X_OK) != 0) {
        write(2, buffer[0], my_strlen(buffer[0]));
        write(2, ": Permission denied.\n", 21);
        data->status = 1;
        return 1;
    }
}

void execute_directory(char **buffer, char *copy_buffer, data_t *data)
{
    struct stat st_t;
    stat(copy_buffer, &st_t);
    if (S_ISDIR(st_t.st_mode)) {
        write(2, buffer[0],  my_strlen(buffer[0]));
        write(2, ": Permission denied.\n", 21);
        data->status = 1;
    }
}

int execute_directory_2(char **buffer, char* copy_buffer, data_t *data)
{
    struct stat st_t2;
    stat(buffer[0], &st_t2);
    if (S_ISDIR(st_t2.st_mode)) {
        write(2, buffer[0],  my_strlen(buffer[0]));
        write(2, ": Permission denied.\n", 21);
        data->status = 1;
        return 1;
    }
    return 0;
}

int executable_handle(char **buffer, char **env, data_t *data)
{
    int returnStatus = 0;
    int child_pid;
    int pid; char *copy_buffer = NULL;
    copy_buffer = my_strdupn(buffer[0], 2);
    if (buffer[0][0] == '/')
        return execute_directory_2(buffer, copy_buffer, data);
    for (int i = 0; i != my_strlen(buffer[0]); i++)
        if (buffer[0][i] == '.' && access(buffer[0], F_OK | X_OK) == 0) {
            execute_directory(buffer, copy_buffer, data);
            pid = getpid();
            child_pid = fork();
            signal(SIGINT, signal_proc_handler);
            if_child_exist(child_pid, buffer, env);
            check_signal(child_pid, data, buffer);
            return 1;
        }
    if (access(buffer[0], F_OK) == 0) {
        return if_cant_execute(buffer, data);
    }
    return 0;
}
