/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** signal_handler functions
*/

/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "../../lib/my/prototypes.h"
#include "../../include/my.h"
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

void signal_print(char *sig)
{
    if (my_strcmp(sig, "Floating point exception") == 0) {
        write(2, "Floating exception", 18);
        return;
    }
    write(2, sig, my_strlen(sig));
}

void signal_proc_handler(int signo)
{
    if (signo == SIGINT) {
        my_putstr_test("\n");
        signal(SIGINT, signal_proc_handler);
    }
}

void core_dumped_or_not(int returnstatus)
{
    if (WCOREDUMP(returnstatus))
        write(2, " (core dumped)", 14);
}

void kill_or_not(char **buffer, int returnstatus, data_t *data, pid_t pid)
{
    if (data->test_i == 1) {
        waitpid(pid, &returnstatus, 0);
    }
}

void check_signal(pid_t pid, data_t *data, char **buffer)
{
    int child_pid = -1;
    int tsig = 0;
    int returnstatus;
    data->test_i = 0;

    child_pid = waitpid(pid, &returnstatus, 0);
    if (WIFSIGNALED(returnstatus)) {
        data->test_i = 1;
        tsig = WTERMSIG(returnstatus);
        if (tsig != 0 && tsig != SIGINT) {
            signal_print(strsignal(tsig));
            core_dumped_or_not(returnstatus);
            my_putstr_test("\n");
            data->status = 0;
        }
    }
    kill_or_not(buffer, returnstatus, data, pid);
}
