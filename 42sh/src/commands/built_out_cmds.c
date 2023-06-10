/*
** EPITECH PROJECT, 2023
** Built out
** File description:
** Check cmd
*/

#include "minishell.h"

int launch_binary(mysh_t *mysh, char **cmd)
{
    if (file_exists(cmd[0])) {
        cmd_execute(mysh, cmd[0], cmd);
        return (1);
    } else {
        my_printf("%s: Command not found.\n", cmd[0]);
        if (mysh->is_a_tty == 0)
            exit(1);
    }
    return (0);
}

static void free_path(char *final_path, char* path)
{
    free(path);
    free(final_path);
}

static int check_step(mysh_t *mysh, char **cmd,
int *cmd_find, int *status)
{
    char *path;
    char *final_path;
    bool global = false;

    for (int i = 0; mysh->paths[i] != NULL; i++) {
        path = merge_strings(mysh->paths[i], "/");
        final_path = merge_strings(path, cmd[0]);
        if (file_exists(final_path)) {
            *cmd_find = 1;
            find_global_cmd(mysh, cmd, final_path, path) ? (global = true)
                : (*status = cmd_execute(mysh, final_path, cmd));
        }
        if (global)
            return (*cmd_find);
        free_path(final_path, path);
    }
    return (0);
}

int check_built_out_cmd(mysh_t *mysh, char **cmd)
{
    int cmd_find = 0;
    int status;

    if (len_str(cmd[0]) > 2 && (cmd[0][0] == '.' || cmd[0][0] == '/')) {
        launch_binary(mysh, cmd);
        return (1);
    }
    if (check_step(mysh, cmd, &cmd_find, &status))
        return (cmd_find);
    if (status != 0)
        return (2);
    return (cmd_find);
}
