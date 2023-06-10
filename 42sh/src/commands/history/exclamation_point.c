/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exclamation point
*/

#include "history.h"

ext_ void error_history_handling(histo_t *histo__, int index)
{
    for (int i = 0; histo__->command_number[i]; i++) {
        if (index == histo__->command_number[i]) {
            histo__->command_not_found = false;
            break;
        } else {
            histo__->command_not_found = true;
        }
    }
}

static char *exec_last_command(char *line, histo_t *histo__)
{
    strcpy(line, histo__->history[histo__->history_size - 1]);
    printf("%s\n", line);
    if (strcmp(line, "history") == 0) {
        history_handling(line, histo__);
    }
    return line;
}

static char *command_found_or_not(char *line, histo_t *histo__, int int_or_char)
{
    if (!histo__->command_not_found) {
        if (histo__->history_size < MAX_HISTORY_SIZE)
            update_history(line, histo__);
        else
            re_write_history(line, histo__);
    }
    if (histo__->command_not_found) {
        if (int_or_char == 0)
            printf("%s: Event not found.\n", line);
        else {
            printf("%d: Event not found.\n", histo__->current_number);
        }
    }
    free(histo__->save);
    return line;
}

ext_ char *check_exclamation_point(char *line, histo_t *histo__, int *index)
{
    bool search_from_letter = false;
    int int_or_char = 0;
    histo__->save = NULL;
    histo__->done = false;
    histo__->command_not_found = false;

    if (line[1] == '!') {
        if (histo__->history_size > 0) {
            return exec_last_command(line, histo__);
        } else {
            histo__->command_not_found = true;
            int_or_char = 1;
        }
    }
    if (line[1] <= '9' && line[1] >= '0')
        find_from_index(line, histo__, index);
    else
        find_from_word(line, histo__, search_from_letter);
    return command_found_or_not(line, histo__, int_or_char);
}
