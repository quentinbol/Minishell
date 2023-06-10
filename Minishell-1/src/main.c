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

void is_alphanum(char **buffer, char **env, data_t *data)
{
    int test = 0;
    if (is_alpha(buffer[1][0]) == 0) {
            write(2, buffer[0], my_strlen(buffer[0]));
            write(2, ": Variable name must begin ",27);
            write(2, "with a letter.\n", 15);
            start_shell(env, data);
    }
    for (int i = 0; i != my_strlen(buffer[1]); i++) {
        if ((buffer[1][i] >= 'a' && buffer[1][i] <= 'z') ||
        (buffer[1][i] >= 'A' && buffer[1][i] <= 'Z') ||
        (buffer[1][i] >= '0' && buffer[1][i] <= '9' || buffer[1][i] == '_')) {
                test++;
            }
    }
    if (test != (my_strlen(buffer[1]) - 1)) {
        write(2, buffer[0], my_strlen(buffer[0]));
        write(2, ": Variable name must contain ",29);
        write(2, "alphanumeric characters.\n", 25);
        start_shell(env, data);
    }
}

int get_line_term(int read, char **copy_env, char *str2, data_t *data)
{
    int save = 0;
    save = data->status;
    if (read == -1) {
        if (isatty(0))
            my_printf("exit\n");
        free_all_k(copy_env, str2);
        exit(data->status);
    }
}

void clear(char **argv, char **env)
{
    int returnStatus;
    int pid = fork();
    if (pid == 0)
        execve("/bin/clear", argv, env);
    waitpid(pid, &returnStatus, 0);
}

int main(int argc, char **argv, char **env)
{
    int returnStatus;
    char **copy_env = NULL;
    data_t *data = malloc(sizeof(data_t));
    data->status = 0;
    copy_env = my_copy_char_array(env);
    for (int i = 0; copy_env[i];  i++)
        my_printf("%s\n", copy_env[i]);
    clear(argv, env);
    if (argc > 1) {
        write(2, "USAGE : ./mysh\n", 15);
        return 84;
    }
    start_shell(copy_env, data);
    return 0;
}
