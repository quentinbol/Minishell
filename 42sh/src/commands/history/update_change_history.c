/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** update_change_history
*/

#include "history.h"

void update_history(char *line, histo_t *histo__)
{
    int i = 0;
    int duplicate_index = 0;

    if (line[0] != '\0') {
        duplicate_index = -1;
        search_duplicate(histo__, &duplicate_index, i, line);
        if (duplicate_index != -1)
            del_duplicate(histo__, duplicate_index, i);
        histo__->history[histo__->history_size] = strdup(line);
        histo__->command_number[histo__->history_size] =
            histo__->current_number;
        time(&histo__->command_time[histo__->history_size]);
        histo__->current_number++;
        histo__->history_size++;
    }
}

void change_index_prev(histo_t *histo__, int i)
{
    histo__->history[i - 1] = histo__->history[i];
    histo__->command_number[i - 1] = histo__->command_number[i];
    histo__->command_time[i - 1] = histo__->command_time[i];
}

void change_history_string_prev(char *line, histo_t *histo__)
{
    histo__->history[MAX_HISTORY_SIZE - 1] = strdup(line);
    histo__->command_number[MAX_HISTORY_SIZE - 1] = histo__->current_number;
    time(&histo__->command_time[MAX_HISTORY_SIZE - 1]);
    histo__->current_number++;
}

void re_write_history(char *line, histo_t *histo__)
{
    char* old_cmd = NULL;
    char* endptr = NULL;
    long int cmd_num = strtol(line + 1, &endptr, 10);

    if (cmd_num <= 0 || cmd_num > (long int)histo__->history_size) {
        return;
    }
    free(histo__->history[0]);
    for (size_t i = 1; i < MAX_HISTORY_SIZE; i++) {
        histo__->history[i - 1] = histo__->history[i];
        histo__->command_number[i - 1] = histo__->command_number[i];
        histo__->command_time[i - 1] = histo__->command_time[i];
    }
    old_cmd = histo__->history[cmd_num - 1];
    histo__->history[MAX_HISTORY_SIZE - 1] = strdup(old_cmd);
    histo__->command_number[MAX_HISTORY_SIZE - 1] = histo__->current_number;
    time(&histo__->command_time[MAX_HISTORY_SIZE - 1]);
    histo__->current_number++;
}

void clear_history(histo_t *histo__)
{
    for (int i = 0; i < histo__->history_size; i++) {
        free(histo__->history[i]);
        histo__->history[i] = NULL;
        histo__->command_number[i] = 0;
    }
    histo__->history_size = 0;
}
