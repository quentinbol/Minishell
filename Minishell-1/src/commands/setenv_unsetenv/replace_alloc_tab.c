/*
** EPITECH PROJECT, 2023
** setenv
** File description:
** senv
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

void count_line(char **copy_2, data_t *data)
{
    while (copy_2[data->n] != NULL) {
        data->n++;
        }
}

char **alloc_new_tab(char *new_string, data_t *data, char **copy_2)
{
    char **new_strings = (char **) malloc(sizeof(char *) * (data->n + 2));

        for (int i = 0; i < data->n; i++) {
            new_strings[i] = my_strdup(copy_2[i]);
        }
        new_strings[data->n] = my_strdup(new_string);
        new_strings[data->n + 1] = NULL;
        return new_strings;
}

char **replace_tab(char **copy_2, char *new_string, data_t *data, int i)
{
    char **new_strings = (char **) malloc(sizeof(char *) * (data->n + 1));

    for (int i = 0; i < data->n; i++) {
        new_strings[i] = my_strdup(copy_2[i]);
        }
        new_strings[i] = my_strdup(new_string);
        new_strings[data->n] = NULL;
        return new_strings;
}

char** replace_tab_bis(char **copy_2, char **test, char *new_string,
                        data_t *data)
{
    for (data->i = 0; copy_2[data->i] != NULL; data->i++) {
        test = my_str_to_word_array_2(copy_2[data->i]);
            if (my_strcmp(test[0], data->cmp_env[0]) == 0) {
                return replace_tab(copy_2, new_string, data, data->i);
            }
        }
        return alloc_new_tab(new_string, data, copy_2);
}

void buffer_two_exist(char **buffer, data_t *data, char* new_line2)
{
    if (buffer[2] != NULL)
            new_line2 = my_strcat(buffer[1], buffer[2]);
        else {
            data->access = 1;
        }
}
