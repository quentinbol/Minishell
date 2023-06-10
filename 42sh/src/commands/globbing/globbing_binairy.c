/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** globbing binairy
*/

#include "minishell.h"

bool find_global_cmd(mysh_t *mysh, char **cmd, char *final_path, char *path)
{
    int i = 0;
    int j = 0;

    while (cmd[i]) {
        if (cmd[i][j] == '*') {
            cmd_execute_global(mysh, cmd);
            free(path);
            free(final_path);
            return (true);
        }
        j++;
        if (!cmd[i][j]) {
            i++;
            j = 0;
        }
    }
    return (false);
}

globbing_t* init_globbing(mysh_t *mysh)
{
    mysh->glob = malloc(sizeof(globbing_t));
    mysh->glob->i = 0;
    mysh->glob->j = 0;
    mysh->glob->new_argv = NULL;
    mysh->glob->count = 0;
    return mysh->glob;
}

int check_glob(mysh_t* mysh, char **cmd)
{
    for (int i = 0; cmd[i]; i++)
        mysh->glob->count++;
    if (glob(cmd[mysh->glob->count - 1], (1 << 4),
        NULL, &mysh->glob->glob_result) != 0) {
        perror("glob");
        return (84);
    }
    return (0);
}

void change_fill_for_glob(mysh_t *mysh, char **cmd)
{
    mysh->glob->new_argv = malloc((mysh->glob->count
                        + mysh->glob->glob_result.gl_pathc) * sizeof(char*));
    for (int i = 0; i != mysh->glob->count; i++)
        mysh->glob->new_argv[i] = cmd[i];
    for (mysh->glob->i = 0, mysh->glob->j = mysh->glob->count - 1;
        mysh->glob->i < mysh->glob->glob_result.gl_pathc; mysh->glob->i++,
        mysh->glob->j++)
        mysh->glob->new_argv[mysh->glob->j] =
            mysh->glob->glob_result.gl_pathv[mysh->glob->i];
    mysh->glob->new_argv[mysh->glob->j] = NULL;
}

int cmd_execute_global(mysh_t *mysh, char **cmd)
{
    __pid_t f = fork();
    int status;

    mysh->glob = init_globbing(mysh);
    if (check_glob(mysh, cmd) == 84)
        return (84);
    change_fill_for_glob(mysh, cmd);
    if (f == -1)
        return (84);
    if (f == 0) {
        if (execvp(mysh->glob->new_argv[0], mysh->glob->new_argv) == -1)
            my_printf("error execution.\n");
    } else
        waitpid(f, &status, 0);
    display_error(status);
    if (status != 0) {
        if (mysh->is_a_tty == 0)
            exit(status);
    }
    return (0);
}
