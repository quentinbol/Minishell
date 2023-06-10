/*
** EPITECH PROJECT, 2023
** Execute
** File description:
** Execute CMD
*/

#include "minishell.h"

int exit_error(mysh_t *mysh, int code)
{
    mysh->return_code = code;
    if (mysh->is_a_tty == 0)
        exit(1);
    return (0);
}

int display_error(int status)
{
    int sig = WTERMSIG(status);
    int core_dump = __WCOREDUMP(status);

    if (WIFSIGNALED(status)) {
        if (sig == 8)
            my_puterror("Floating exception");
        if (sig != 8)
            my_puterror(strsignal(WTERMSIG(status)));
        if (core_dump != 0)
            my_puterror(" (core dumped)");
        my_puterror("\n");
    }
    if (status != 0)
        return (1);
    return (0);
}

int cmd_execute(mysh_t *mysh, char *path, char **cmd)
{
    __pid_t f;
    int status;
    int have_error;

    if (is_directory(cmd[0])) {
        my_printf("%s: Permission denied.\n", cmd[0]);
        exit_error(mysh, 1);
        return (1);
    }
    if ((f = fork()) == -1)
        return (84);
    if (f == 0) {
        if (execve(path, cmd, mysh->env) == -1)
            my_printf("error execution.\n");
    } else
        waitpid(f, &status, 0);
    have_error = display_error(status);
    if (status != 0)
        exit_error(mysh, 1);
    return (have_error);
}
