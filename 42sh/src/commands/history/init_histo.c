/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_histo
*/

#include "history.h"

histo_t* init_histo(histo_t *histo__)
{
    histo__ = malloc(sizeof(histo_t));
    histo__->history[MAX_HISTORY_SIZE] = NULL;
    histo__->command_number[MAX_HISTORY_SIZE] = 0;
    histo__->command_time[MAX_HISTORY_SIZE] = 0;
    histo__->current_number = 1;
    histo__->history_size = 0;
    histo__->save = NULL;
    histo__->command_not_found = false;
    return histo__;
}
