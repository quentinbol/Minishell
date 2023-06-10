/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** find from word
*/

#include "history.h"

ext_ void find_from_char(histo_t *histo__, char *line, int i,
    bool search_from_letter)
{
    if (strcmp(line, histo__->history[i]) == 0) {
        strcpy(line, histo__->history[i]);
        if (!search_from_letter)
            printf("%s\n", line);
        search_from_letter = true;
        if (strcmp(line, "history") == 0) {
            history_handling(line, histo__);
        }
        histo__->done = true;
    }
}

ext_ void find_from_char2(histo_t *histo__, char *line, int i,
    bool search_from_letter)
{
    size_t count = 0;

    for (int k = 0; line[k]; k++) {
        if (line[k] == histo__->history[i][k] && !search_from_letter)
            count++;
    }
    if (count == strlen(line)) {
        histo__->command_not_found = false;
        histo__->save = malloc(sizeof(char) * strlen(histo__->history[i]));
        strcpy(histo__->save, histo__->history[i]);
    } else
        histo__->command_not_found = true;
}

ext_ void check_save(histo_t *histo__, char *line, bool search_from_letter)
{
    if (histo__->save != NULL) {
        histo__->command_not_found = false;
        strcpy(line, histo__->save);
        if (!search_from_letter)
            printf("%s\n", line);
        search_from_letter = true;
        if (strcmp(line, "history") == 0)
            history_handling(line, histo__);
    }
}

ext_ void final_find(char *line, histo_t *histo__, bool search_from_letter)
{
    for (int i = 0; i != histo__->history_size; i++) {
        if (histo__->done)
            break;
        find_from_char2(histo__, line, i, search_from_letter);
    }
}

ext_ void find_from_word(char *line, histo_t *histo__, bool search_from_letter)
{
    del_first_char(line);
    for (int i = 0; i != histo__->history_size; i++) {
        if (histo__->done)
            break;
        find_from_char(histo__, line, i, search_from_letter);
    }
    if (!histo__->done) {
        final_find(line, histo__, search_from_letter);
    }
    check_save(histo__, line, search_from_letter);
}
