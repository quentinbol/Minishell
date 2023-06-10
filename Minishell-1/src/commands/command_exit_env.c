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

void free_all_k(char **copy_env, char *str2)
{
    for (int i = 0; copy_env[i] != NULL; i++)
            free(copy_env[i]);
    free(copy_env);
    free(str2);
}

int environnement(char **buffer, char **env)
{
    if (my_strcmp(buffer[0], "env") == 0) {
        print_env(env);
        free(buffer[0]);
        return 1;
    } else {
        return 0;
    }
}

void print_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        my_printf("%s\n", env[i]);
    }
}

void bad_formed_number(char **buffer, char **env, data_t *data)
{
    for (int i = 0; buffer[1][i] != '\0'; i++) {
        if (buffer[1][i] > '9' || buffer[1][i] < '0') {
            write(2, "exit: Badly formed number.\n", 27);
            data->status = 1;
            start_shell(env, data);
        }
    }
}

void exit_shell(char **buffer, char **env, char* str2, data_t *data)
{
    if (my_strcmp(buffer[0], "exit") == 0) {
        if (buffer[1] == NULL) {
            free_all_k(env, str2);
            exit(data->status);
        }
        if (buffer[1][0] >= '0' && buffer[1][0] <= '9') {
            bad_formed_number(buffer, env, data);
            my_printf("exit\n");
            data->status = my_getnbr(buffer[1]);
            free_all_k(env, str2);
            exit(data->status);
            }
        if (num_check(buffer[1]) == 84) {
                write(2, "exit: Expression Syntax.\n", 25);
                data->status = 1;
                start_shell(env, data);
            }
    }
}
