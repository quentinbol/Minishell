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

void if_child_exist(int child_pid, char **buffer, char **env)
{
    if (child_pid == 0) {
        exit(execve(buffer[0], buffer, env));
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

int executable_handle(char **buffer, char **env, data_t *data)
{
    int returnStatus = 0;
    int child_pid;
    int pid;
    for (int i = 0; i != my_strlen(buffer[0]); i++)
        if (buffer[0][i] == '.' && access(buffer[0], F_OK | X_OK) == 0) {
            pid = getpid();
            child_pid = fork();
            signal(SIGINT, signal_proc_handler);
            if_child_exist(child_pid, buffer, env);
            check_signal(child_pid, data, buffer);
            return 1;
        }
        if (access(buffer[0], F_OK) == 0)
            return if_cant_execute(buffer, data);
        return 0;
}
