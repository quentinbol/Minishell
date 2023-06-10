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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void open_cd(char **buffer, data_t *data, char* pwd, char **env)
{
    char **new_pwd = NULL;
    char *slash = "/";
    int k = 0;
    char **new_strings = (char **) malloc(sizeof(char *) * (data->n + 1));
    chdir(buffer[1]);
}

char** change_directory(char **buffer, data_t *data, char **env)
{
    char pwd[1024];
    getcwd(pwd, sizeof(pwd));
    struct stat st;
    stat(buffer[1], &st);
    if (S_ISREG(st.st_mode)) {
            write(2, buffer[1], my_strlen(buffer[1]));
            write(2, ": Not a directory.\n", 19);
            data->status = 1;
            return NULL;
        }
    if (opendir(buffer[1]) == NULL) {
        write(2, buffer[1], my_strlen(buffer[1]));
        write(2, ": No such file or directory.\n", 29);
        data->status = 1;
        return NULL;
    }
    open_cd(buffer, data, pwd, env);
}

void back_to_home(char **buffer, char **env)
{
    int k = 0;

    char **home;
    for (int i = 0; env[i]; i++) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M'
            && env[i][3] == 'E') {
            home = my_str_to_word_array_2(env[i]);
            chdir(home[1]);
        }
    }
}

int directory_exist(char **buffer, char **env, data_t *data)
{
    if (buffer[1] != NULL) {
        if (change_directory(buffer, data, env) == 0) {
            return 0;
        } else {
            return 84;
        }
    } else {
        if (buffer[1] == NULL)
            back_to_home(buffer, env);
    }
}

int cd_handle(char **buffer, char **env, data_t *data)
{
    if (my_strcmp(buffer[0], "cd") == 0) {
        free(buffer[0]);
        if (buffer[1] != NULL && (my_strcmp(buffer[1], "-") == 0)) {
            check_oldpwd(buffer, env, data);
            return 1;
        }
        if (buffer[1] != NULL && (my_strcmp(buffer[1], "~") == 0)) {
            back_to_home(buffer, env);
            return 1;
        }
        if (directory_exist(buffer, env, data) == 0) {
            return 1;
        } else {
            return 84;
        }
    }
    return 0;
}
