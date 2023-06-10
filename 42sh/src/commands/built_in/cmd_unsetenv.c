/*
** EPITECH PROJECT, 2023
** UnsetEnv
** File description:
** unsetenv cmd
*/

#include "minishell.h"

int cmp_data_env(char *str, char *data)
{
    for (int i = 0; str[i] != '=' && str[i] != '\0'; i++) {
        if (str[i] != data[i])
            return (0);
    }
    return (1);
}

int have_element_in_env(mysh_t *mysh, char *str)
{
    for (int i = 0; mysh->env[i] != NULL; i++) {
        if (cmp_data_env(mysh->env[i], str))
            return (1);
    }
    return (0);
}

int my_unsetenv(mysh_t *mysh, char **cmd)
{
    int n = 0;
    char **new_array = malloc(sizeof(char *) * len_array(mysh->env));

    for (int i = 0; mysh->env[i] != NULL; i++) {
        if (cmp_data_env(mysh->env[i], cmd[1]) == 0) {
            new_array[n] = my_strdup(mysh->env[i]);
            n += 1;
        }
    }
    new_array[n] = NULL;
    free_array(mysh->env);
    mysh->env = copy_array(new_array);
    free_array(new_array);
    return (0);
}

int cmd_unsetenv(mysh_t *mysh, char **cmd)
{
    int len = len_array(cmd);

    if (len == 1) {
        my_printf("unsetenv: Too few arguments.\n");
        if (mysh->is_a_tty == 0)
            exit(1);
        return (0);
    }
    if (have_element_in_env(mysh, cmd[1]) == 0)
        return (0);
    my_unsetenv(mysh, cmd);
    return (0);
}
