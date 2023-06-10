/*
** EPITECH PROJECT, 2023
** Minishell
** File description:
** Init minshell
*/

#include "minishell.h"

char **get_paths(char **env)
{
    char *path = get_env("PATH", env);
    char **array;

    array = buffer_to_word_array(path, ':');
    free(path);
    return (array);
}

int mysh_destroy(mysh_t *mysh)
{
    free_array(mysh->paths);
    free_array(mysh->env);
    free_history(mysh->histo__);
    free_alias(mysh->alias);
    return (0);
}

mysh_t mysh_init(char **env)
{
    mysh_t mysh;

    mysh.error = 0;
    if (signal(SIGINT, &handler) == SIG_ERR)
        mysh.error = 1;
    mysh.prompt = "$> ";
    get_prompt(mysh.prompt);
    mysh.env = copy_array(env);
    mysh.paths = get_paths(env);
    mysh.is_launch = 1;
    mysh.is_a_tty = isatty(0);
    mysh.return_code = 0;
    mysh.alias = list_create();
    return (mysh);
}
