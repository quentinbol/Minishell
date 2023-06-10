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
#include <errno.h>

void if_wrong_architecture(char **buffer)
{
    if (errno == ENOEXEC) {
        my_printf("%s: Exec format error. ", buffer[0]);
        my_printf("Wrong Architecture.\n");
    }
}

void print_directory(data_t *data)
{
    char pwd[1024];

    if (getcwd(pwd, sizeof(pwd)) != NULL) {
        my_printf("%s\n", pwd);
    } else {
        write(2, "error\n", 6);
        data->status = 1;
    }
}

int pwd(char **buffer, data_t *data)
{
        if (buffer[1] != NULL) {
            write(2, "pwd: ignoring non-option arguments\n", 35);
        }
        print_directory(data);
        return 1;
}
