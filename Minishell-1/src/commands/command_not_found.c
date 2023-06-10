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

int command_not_found(char **buffer, char *str2, char **env, data_t *data)
{
    if (my_strcmp(buffer[0], "unsetenv") != 0 &&
        my_strcmp(buffer[0], "setenv") != 0) {
        write(2, buffer[0], my_strlen(buffer[0]));
        write(2, ": Command not found.\n", 21);
        data->status;
    }
    exit(1);

}
