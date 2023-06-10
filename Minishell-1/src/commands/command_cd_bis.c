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

void old_pwd(char **buffer, char **env, data_t *data)
{
    char **new_env = NULL;

    for (int i = 0; env[i]; i++) {
        new_env = my_str_to_word_array_2(env[i]);
        if (my_strcmp(new_env[0], "OLDPWD") == 0)
            chdir(new_env[1]);

    }
}

int check_oldpwd(char **buffer, char **env, data_t *data)
{
    if (my_strcmp(buffer[1], "-") == 0) {
        old_pwd(buffer, env, data);
    }
}
