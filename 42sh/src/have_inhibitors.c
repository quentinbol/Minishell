/*
** EPITECH PROJECT, 2023
** have_inhibitors.c
** File description:
** if have inhibitors in input
*/

#include "minishell.h"

int have_inhibitors(const char *input)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\\')
            return 0;
    }
    return 1;
}

void exe_inhibitors(inhibitors_t inhibitors)
{
    int pid = fork();
    int wait = 0;

    if (pid == -1)
        return;
    if (pid == 0) {
        execvp(inhibitors.tokens[0], inhibitors.tokens);
    } else
        waitpid(pid, &wait, 0);
}
