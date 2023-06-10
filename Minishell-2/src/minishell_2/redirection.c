/*
** EPITECH PROJECT, 2023
** redirection
** File description:
** redirection for minishell
*/

#include "../../lib/my/prototypes.h"
#include "../../include/my.h"
#include <sys/wait.h>
#include <sys/signal.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void boucle_redirect(char **args, data_t *data, int *fd)
{
    for (int i = 1; i != data->number - 1; i++)
        open(args[i], O_CREAT, 0644);
    if (data->double_red == 1)
        *fd = open(args[data->number - 1], ADD_TO_FILE, 0644);
    else {
        *fd = open(args[data->number - 1], REMPLACE_FILE, 0644);
    }
}

void redirection_handling(char **parsing, data_t *data, char **env, char *str2)
{
    char **args;
    int status;
    pid_t pid;
    int fd = -1;
    args = my_str_to_word_array(parsing[0]);
    boucle_redirect(parsing, data, &fd);
    data->path = args[0];
    pid = fork();

    if (pid == 0) {
        if (fd != -1) {
            dup2(fd, STDOUT_FILENO);
            close(fd);
            if_slash(parsing, 0, env, data);
            execve(data->path, args, NULL);
            exit(1);
        }
    } else if (pid > 0)
        waitpid(pid, &status, 0);
}

void clean_string_and_count(char **args, data_t *data)
{
    for (int i = 0; args[i]; i++) {
        data->number++;
        clean_string(args[i]);
    }
}

void redirection_handling_2(char *parsing, data_t *data, char **env, char *str2)
{
    char **args;
    int status;
    pid_t pid;
    int fd = -1;
    args = my_str_to_word_array_gen(parsing, '>');
    clean_string_and_count(args, data);
    boucle_redirect(args, data, &fd);
    args = my_str_to_word_array_gen(args[0], ' ');
    data->path = args[0];
    pid = fork();
    if (pid == 0) {
        if (fd != -1) {
            dup2(fd, STDOUT_FILENO);
            close(fd);
            if_slash(args, 0, env, data);
            execve(data->path, args, NULL);
            exit(1);
        }
    } else if (pid > 0)
        waitpid(pid, &status, 0);
}
