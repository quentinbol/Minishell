/*
** EPITECH PROJECT, 2023
** CMD CD
** File description:
** cd command
*/

#include "minishell.h"

static int remplace_wd(mysh_t *mysh, char *name)
{
    int i = 0;
    char *str;
    char *buffer = NULL;
    char *path;
    size_t size = 4440;

    for (; mysh->env[i] != NULL; i++) {
        if (str_start_with(mysh->env[i], name))
            break;
    }
    path = getcwd(buffer, size);
    str = merge_strings(name, path);
    free(mysh->env[i]);
    mysh->env[i] = my_strdup(str);
    free(str);
    free(path);
    return (0);
}

static int cmd_cd_exec(mysh_t *mysh, int len, char **cmd, char *oldpwd)
{
    if (len == 2) {
        if (my_strcmp(cmd[1], "-") == 0) {
            chdir(oldpwd);
            return (1);
        }
        if (is_directory(cmd[1]) == 0) {
            my_printf("%s: No such file or directory.\n", cmd[1]);
            exit_error(mysh, 1);
            return (1);
        }
        if (chdir(cmd[1]) == -1)
            my_printf("%s: error cd.\n", cmd[1]);
    }
    return (0);
}

int env_add_oldpwd(mysh_t *mysh)
{
    int i = 0;
    int n = 0;
    char **new_array;

    for (; mysh->env[i] != NULL; i++) {
        if (str_start_with(mysh->env[i], "OLDPWD="))
            n = i;
    }
    if (n != 0)
        return (0);
    new_array = malloc(sizeof(char *) * (i + 2));
    for (i = 0; mysh->env[i] != NULL; i++)
        new_array[i] = my_strdup(mysh->env[i]);
    new_array[i] = my_strdup("OLDPWD=");
    new_array[i + 1] = NULL;
    free_array(mysh->env);
    mysh->env = copy_array(new_array);
    free_array(new_array);
    return (0);
}

int cmd_cd_step(mysh_t *mysh, char **cmd, int len, char *oldpwd)
{
    char *home_directory = get_env("HOME", mysh->env);

    if (cmd_cd_exec(mysh, len, cmd, oldpwd)) {
        remplace_wd(mysh, "PWD=");
        free(oldpwd);
        free(home_directory);
        return (1);
    }
    if (len == 1) {
        if (check_env("HOME", mysh->env) == 0) {
            my_printf("cd: No home directory.\n");
            exit_error(mysh, 1);
        }
        chdir(home_directory);
    }
    free(home_directory);
    return (0);
}

int cmd_cd(mysh_t *mysh, char **cmd)
{
    int len = len_array(cmd);
    char *oldpwd = get_env("OLDPWD", mysh->env);

    env_add_oldpwd(mysh);
    remplace_wd(mysh, "OLDPWD=");
    if (len > 2) {
        my_printf("cd: Too many arguments.\n");
        if (mysh->is_a_tty == 0)
            exit(1);
    }
    if (cmd_cd_step(mysh, cmd, len, oldpwd))
        return (0);
    remplace_wd(mysh, "PWD=");
    free(oldpwd);
    return (0);
}
