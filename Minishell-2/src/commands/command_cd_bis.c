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

int check_oldpwd(char **buffer, char **env, data_t *data, char* old)
{
    char **new_env = NULL;
    int exist = 0;

    if (my_strcmp(buffer[1], "-") == 0) {
        chdir(old);
    }
}
