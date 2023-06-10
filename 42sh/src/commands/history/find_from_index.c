/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** find from index
*/

#include "history.h"

ext_ void find_index(histo_t *histo__, char *line, int *index, int i)
{
    if (*index == histo__->command_number[i]) {
        strcpy(line, histo__->history[i]);
        printf("%s\n", line);
        if (strcmp(line, "history") == 0)
            history_handling(line, histo__);
    }
}

ext_ void find_from_index(char *line, histo_t *histo__, int *index)
{
    for (int i = 2; line[i]; i++)
        if (line[i] > '9' || line[i] < '0') {
            printf("%s: Event not found.\n", line);
            histo__->command_not_found = true;
        }
    del_first_char(line);
    *index = atoi(line);
    error_history_handling(histo__, *index);
    for (int i = 0; histo__->history[i]; i++)
        find_index(histo__, line, index, i);
}
