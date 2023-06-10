/*
** EPITECH PROJECT, 2023
** RUN
** File description:
** RUN PROJECT
*/

#include "minishell.h"

static int display_cmd_notfound(char **cmd)
{
    for (int i = 0; cmd[0][i] != '\0'; i++) {
        if (cmd[0][i] != '\\')
            my_printf("%c", cmd[0][i]);
    }
    my_printf(": Command not found.\n");
    return (0);
}

int check_cmd(mysh_t *mysh, char *buffer)
{
    char **cmd = buffer_to_word_array(buffer, ' ');

    if (my_strcmp(cmd[0], "alias") != 0)
        cmd = replace_aliases(mysh, cmd);
    if (my_strlen(cmd[0]) == 0) {
        free_array(cmd);
        return (0);
    }
    if (check_built_in_cmd(mysh, cmd)) {
        free_array(cmd);
        return (0);
    }
    if (check_built_out_cmd(mysh, cmd) != 1) {
        display_cmd_notfound(cmd);
        free_array(cmd);
        return (1);
    }
    free_array(cmd);
    return (0);
}

int check_pipes(mysh_t *mysh, char *buffer)
{
    if (have_inhibitors(buffer) == 0) {
        inhibitors(buffer, mysh->inhibitors);
        return 0;
    }
    if (have_pipe(buffer) == 0)
        return (check_cmd(mysh, buffer));
    else
        execute_pipes(mysh, buffer);
    return (0);
}

int check_prompt(mysh_t *mysh, char *buffer)
{
    char **all_cmds = buffer_to_word_array(buffer, ';');
    int status = 0;

    for (int i = 0; all_cmds[i] != NULL; i++)
        status = check_pipes(mysh, all_cmds[i]);
    free_array(all_cmds);
    return (status);
}

int mysh_run(mysh_t *mysh)
{
    size_t bufsize = 9999;
    char *buffer = malloc(sizeof(char) * bufsize);
    ssize_t size;
    int status;

    while (mysh->is_launch) {
        if (mysh->is_a_tty)
            my_printf("%s", mysh->prompt);
        if ((size = getline(&buffer, &bufsize, stdin)) == -1) {
            if (mysh->is_a_tty)
                my_printf("exit\n", buffer);
            break;
        }
        check_history(mysh, buffer);
        status = check_prompt(mysh, buffer);
    }
    free(buffer);
    return (status);
}
