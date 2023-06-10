/*
** EPITECH PROJECT, 2023
** unsetenv
** File description:
** env
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

void check_if_exist(char **buffer, char **final_copy, data_t *data)
{
    char **buffer3 = my_str_to_word_array_2(final_copy[data->num_lines]);
    if (my_strcmp(buffer[1], buffer3[0]) == 0) {
        data->i++;
        data->suppression = data->num_lines;
    }
    data->num_lines++;
}

char **check_unsetenv(char **buffer, char **final_copy, data_t *data)
{
    if (buffer[0] == NULL)
            start_shell(final_copy, data);
    if (my_strcmp(buffer[0], "unsetenv") == 0) {
        if (buffer[1] == NULL) {
            my_printf("unsetenv: Too few arguments.\n");
            data->status = 1;
            start_shell(final_copy, data);
        }
        unsetenv_f(buffer, final_copy, data);
    }
}

void delete_line(char **final_copy, data_t *data, int line_to_delete)
{
    for (int i = line_to_delete; i < data->num_lines - 1; i++) {
        final_copy[i] = final_copy[i + 1];
    }
}

char **unsetenv_f(char **buffer, char **final_copy, data_t *data)
{
    int line_to_delete = 0;
    data->num_lines = 0;
    data->suppression = 0;
    data->i = 0;

    while (final_copy[data->num_lines] != NULL) {
        check_if_exist(buffer, final_copy, data);
    }
    if (data->i = 0) {
        return final_copy;
    } else {
        line_to_delete = data->suppression;
        if (line_to_delete >= 0 && line_to_delete < data->num_lines) {
            delete_line(final_copy, data, line_to_delete);
            final_copy[data->num_lines - 1] = NULL;
            data->num_lines--;
        }
    }
    data->return_status = 0;
    return final_copy;
}
