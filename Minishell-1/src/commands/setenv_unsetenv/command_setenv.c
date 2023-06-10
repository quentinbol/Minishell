/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "../../../lib/my/prototypes.h"
#include "../../../include/my.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

void verif_if_buffer_null(char **copy_2, char **buffer, char **final_env,
                            data_t *data)
{
    count_line(copy_2, data);
    final_env = my_str_to_word_array_2(copy_2[data->n - 1]);
    data->cmp_env = my_str_to_word_array_2(buffer[1]);
}

char **setenv_null(char **buffer, char **env, data_t *data)
{
    char *str_env = "=";

    free(env[0]);
    my_strcat(buffer[1], str_env);
    env[0] = (char * ) malloc(sizeof(my_strlen(buffer[1])));
    if (buffer[2] == NULL) {
        env[0] = buffer[1];
        return env;
    }
    if (buffer[2] != NULL) {
        my_strcat(buffer[1], buffer[2]);
        env[0] = buffer[1];
    }
    if (buffer[3] != NULL) {
        write(1, buffer[0], my_strlen(buffer[0]));
        write(1, ": Too many arguments.\n", 22);
        data->status = 1;
    }
    return env;
}

char **invalid_number(char **buffer, data_t *data, char **env)
{
    write(1, buffer[0], my_strlen(buffer[0]));
    write(1, ": Too many arguments.\n", 22);
    data->return_status = 1;
    return env;
}

char **check_env(char **buffer, char **env, data_t *data, char *str2)
{
    if (my_strcmp(buffer[0], "setenv") != 84) {
        if (env[0] == NULL) {
            return setenv_null(buffer, env, data);
        }
        if (buffer[3] != NULL && number_word(str2) > 3) {
            return invalid_number(buffer, data, env);
        }
        return set_env(buffer, env, data, str2);
    }
    return env;
}

char** set_env(char **buffer, char **env, data_t *data, char *str2)
{
    char **copy_2 = NULL;
    char **test = NULL;
    char *str_env = "=";
    char **final_env = NULL;
    char *new_string = NULL;
    char* new_line2 = NULL;
    copy_2 = my_copy_char_array(env);
    data->n = 0; data->access = 0;
    if (buffer[1] != NULL) {
            my_strcat(buffer[1], str_env);
    is_alphanum(buffer, env, data);
    if (buffer[2] != NULL)
        new_line2 = my_strcat(buffer[1], buffer[2]);
        new_string = buffer[1];
        verif_if_buffer_null(copy_2, buffer, final_env, data);
        return replace_tab_bis(copy_2, test, new_string, data);
    } else {
        print_env(env);
    }
    return copy_2;
}
