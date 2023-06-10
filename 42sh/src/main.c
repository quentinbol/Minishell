/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** MAIN 42SH
*/

#include "minishell.h"

int main(int ac, char **av, char **env)
{
    mysh_t mysh = mysh_init(env);
    mysh.histo__ = init_histo(mysh.histo__);
    int status;

    if (mysh.error) {
        my_printf("ERROR Initialisation.\n");
        return (84);
    }
    status = mysh_run(&mysh);
    mysh_destroy(&mysh);
    return (status);
}
