/*
** EPITECH PROJECT, 2023
** Sig handler
** File description:
** HANDLER of My shell
*/

#include "minishell.h"

char *get_prompt(char *new)
{
    static char *prompt;

    if (new != NULL)
        prompt = new;
    return (prompt);
}

void handler(int signum)
{
    if (signum == SIGINT)
        my_printf("\n%s", get_prompt(NULL));
    if (signum == SIGSEGV)
        my_printf("SIG segv\n");
}
