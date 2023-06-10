/*
** EPITECH PROJECT, 2023
** Setenv
** File description:
** Setenv
*/

#include "minishell.h"

static int add_to_end(mysh_t *mysh, char **cmd, int len)
{
    char *str = merge_strings(cmd[1], "=");
    char **new_array = malloc(sizeof(char *) * (len_array(mysh->env) + 2));
    char *m;
    int i = 0;

    if (len == 3) {
        m = my_strdup(str);
        free(str);
        str = merge_strings(m, cmd[2]);
        free(m);
    }
    for (; mysh->env[i] != NULL; i++)
        new_array[i] = my_strdup(mysh->env[i]);
    new_array[i] = my_strdup(str);
    new_array[i + 1] = NULL;
    free_array(mysh->env);
    mysh->env = copy_array(new_array);
    free_array(new_array);
    free(str);
    return (0);
}

static int check_errors_setenv(mysh_t *mysh, char **cmd)
{
    if (my_char_isalpha(cmd[1][0]) == 0) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        exit_error(mysh, 1);
        return (1);
    }
    if (my_str_isalpha(cmd[1]) == 0) {
        my_printf("setenv: Variable name must contain");
        my_printf(" alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

int remplace(mysh_t *mysh, char **cmd, int i)
{
    char *str = merge_strings(cmd[1], "=");
    char *fstr = merge_strings(str, cmd[2]);

    free(mysh->env[i]);
    mysh->env[i] = my_strdup(fstr);
    free(str);
    free(fstr);
    return (0);
}

int remplace_if_exists(mysh_t *mysh, char **cmd)
{
    for (int i = 0; mysh->env[i] != NULL; i++) {
        if (cmp_data_env(mysh->env[i], cmd[1])) {
            remplace(mysh, cmd, i);
            return (1);
        }
    }
    return (0);
}

int cmd_setenv(mysh_t *mysh, char **cmd)
{
    int len = len_array(cmd);

    if (len == 1) {
        cmd_env(mysh);
        return (0);
    }
    if (len > 3) {
        my_printf("setenv: Too many arguments.\n");
        if (mysh->is_a_tty == 0)
            exit(1);
        return (0);
    }
    if (check_errors_setenv(mysh, cmd))
        return (0);
    if (remplace_if_exists(mysh, cmd))
        return (0);
    add_to_end(mysh, cmd, len);
    return (0);
}
