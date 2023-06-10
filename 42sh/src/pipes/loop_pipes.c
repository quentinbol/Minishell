/*
** EPITECH PROJECT, 2023
** LOOP pipes
** File description:
** loop_pipes
*/

#include "minishell.h"

int proc_child(char ***cmd, int fd_in, int p[2],
char **env, int i)
{
    dup2(fd_in, STDIN_FILENO);
    if (cmd[i + 1] != NULL)
        dup2(p[1], STDOUT_FILENO);
    close(p[0]);
    execve(cmd[i][0], cmd[i], env);
    return (0);
}

int proc_parent(int pid, int *fd_in, int p[2])
{
    int status;

    waitpid(pid, &status, 0);
    close(p[1]);
    *fd_in = p[0];
    return (status);
}

int loop_pipes(char ***cmd, char **env)
{
    int p[2];
    pid_t pid;
    int fd_in = 0;

    for (int i = 0; cmd[i] != NULL; i++) {
        pipe(p);
        if ((pid = fork()) == -1)
            return (84);
        if (pid == 0)
            proc_child(cmd, fd_in, p, env, i);
        else
            proc_parent(pid, &fd_in, p);
    }
    return (0);
}
