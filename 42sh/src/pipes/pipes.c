/*
** EPITECH PROJECT, 2023
** Pipes
** File description:
** pipes GESTION
*/

#include "minishell.h"

int have_pipe(char *buffer)
{
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '|')
            return (1);
    }
    return (0);
}

int free_triple_array(char ***array)
{
    for (int i = 0; array[i] != NULL; i++)
        free_array(array[i]);
    free(array);
    return (0);
}

char *find_path(mysh_t *mysh, char *prog_name)
{
    char *path;
    char *final_path;

    for (int i = 0; mysh->paths[i] != NULL; i++) {
        path = merge_strings(mysh->paths[i], "/");
        final_path = merge_strings(path, prog_name);
        if (file_exists(final_path)) {
            free(path);
            free(prog_name);
            return (final_path);
        }
        free(path);
        free(final_path);
    }
    free(prog_name);
    return (NULL);
}

int execute_pipes(mysh_t *mysh, char *buffer)
{
    char **all_cmds = buffer_to_word_array(buffer, '|');
    char ***array = malloc(sizeof(char **) * (len_array(all_cmds) + 1));
    int i = 0;

    for (; all_cmds[i] != NULL; i++)
        array[i] = buffer_to_word_array(all_cmds[i], ' ');
    array[i] = NULL;
    for (int i = 0; array[i] != NULL; i++)
        array[i][0] = find_path(mysh, array[i][0]);
    loop_pipes(array, mysh->env);
    free_triple_array(array);
    free_array(all_cmds);
    return (0);
}
