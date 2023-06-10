/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history.c
*/

#include "minishell.h"

ext_ void print_history(histo_t *histo__, char *line)
{
    char **change_time = NULL;

    for (int i = 0; i < histo__->history_size; i++) {
        change_time = my_str_to_word_array
            (asctime(localtime(&histo__->command_time[i])));
        change_time[3][strcspn(line, "\n")] = '\0';
        change_time = my_str_to_word_array_gen(change_time[3], ':');
        printf("   %d  %s:%s    %s\n", histo__->command_number[i],
            change_time[0], change_time[1], histo__->history[i]);
    }
}

ext_ void history_handling(char *line, histo_t *histo__)
{
    if (histo__->history_size < MAX_HISTORY_SIZE) {
        update_history(line, histo__);
    } else {
        free(histo__->history[0]);
        for (size_t i = 1; i < MAX_HISTORY_SIZE; i++) {
            change_index_prev(histo__, i);
        }
        change_history_string_prev(line, histo__);
    }
    print_history(histo__, line);
}

ext_ void free_history(histo_t *histo__)
{
    for (int i = 0; i < histo__->history_size; i++)
        free(histo__->history[i]);
}

ext_ char* history(char *line, histo_t *histo__)
{
    int index = 0;

    line[my_strcspn(line, "\n")] = '\0';
    if (strcmp(line, "history") == 0) {
        history_handling(line, histo__);
    } else {
        index = -1;
        if (line[0] == '!')
            return check_exclamation_point(line, histo__, &index);
        if (histo__->history_size < MAX_HISTORY_SIZE) {
            update_history(line, histo__);
        } else {
            re_write_history(line, histo__);
        }
    }
    if (strcmp(line, "history -c") == 0)
        clear_history(histo__);
    return line;
}

ext_ int check_history(mysh_t *mysh, char *buffer)
{
    buffer = strdup(history(buffer, mysh->histo__));
    if (buffer == NULL)
        return (84);
    return (0);
}
