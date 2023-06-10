/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** duplicate_history
*/

#include "history.h"

ext_ void del_duplicate(histo_t *histo__, int duplicate_index, int i)
{
    free(histo__->history[duplicate_index]);
    for (i = duplicate_index; i < histo__->history_size - 1; i++) {
        histo__->history[i] = histo__->history[i + 1];
        histo__->command_number[i] = histo__->command_number[i + 1];
        histo__->command_time[i] = histo__->command_time[i + 1];
    }
    histo__->history_size--;
}

ext_ void search_duplicate(histo_t *histo__, int *dup_index, int i, char *line)
{
    for (i = 0; i < histo__->history_size; i++) {
        if (strcmp(histo__->history[i], line) == 0) {
            *dup_index = i;
            break;
        }
    }
}
