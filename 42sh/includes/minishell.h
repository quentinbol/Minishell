/*
** EPITECH PROJECT, 2023
** Minishell
** File description:
** MINISHELL
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include <stddef.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <string.h>
    #include <errno.h>
    #include <stdbool.h>
    #include <glob.h>
    #include "history.h"
    #include "globbing.h"
    #include "my.h"
    #include "aliases.h"

typedef struct inhibitors_s {
    int num_tokens;
    int capacity;
    char **tokens;
    int input_length;
    int start;
    bool in_single_quote;
    bool in_double_quote;
    bool escaped;
    int backslash_count;
    int length;
} inhibitors_t;

typedef struct mysh_s {

    globbing_t *glob;
    inhibitors_t inhibitors;
    histo_t *histo__;
    alias_t *alias;
    int is_launch;
    char **env;
    char *prompt;
    char **paths;
    int is_a_tty;
    int return_code;
    int error;
} mysh_t;

int mysh_run(mysh_t *mysh);
int display_error(int status);
int cmd_execute_global(mysh_t *mysh, char **cmd);
bool builtin_or_not(char* cmd);
void which(mysh_t *mysh, char* cmd);
void where(mysh_t *mysh, char* cmd);
int check_history(mysh_t *mysh, char *buffer);
int have_pipe(char *buffer);
int execute_pipes(mysh_t *mysh, char *buffer);
int loop_pipes(char ***cmd, char **env);
int str_start_with(char *str, char *elem);
int file_exists(char *path);
int file_is_executable(char *path);
int check_built_in_cmd(mysh_t *mysh, char **cmd);
int check_built_out_cmd(mysh_t *mysh, char **cmd);
int cmd_execute(mysh_t *mysh, char *path, char **cmd);
void handler(int signum);
char *get_prompt(char *new);
int check_env(char *var_name, char **env);
char *get_env(char *name, char **env);
mysh_t mysh_init(char **env);
int mysh_destroy(mysh_t *mysh);
int cmd_setenv(mysh_t *mysh, char **cmd);
int cmp_data_env(char *str, char *data);
int cmd_unsetenv(mysh_t *mysh, char **cmd);
int cmd_env(mysh_t *mysh);
int cmd_exit(mysh_t *mysh, char **cmd);
int cmd_cd(mysh_t *mysh, char **cmd);
int is_directory(char *path);
int exit_error(mysh_t *mysh, int code);
void inhibitors(const char *input, inhibitors_t inhibitors);
int have_inhibitors(const char *input);
void exe_inhibitors(inhibitors_t inhibitors);
int is_alias(mysh_t *mysh, char *cmd);
char **replace_aliases(mysh_t *mysh, char **cmd);
void alias(mysh_t *mysh, char **cmd);

#endif /* !MINISHELL_H_ */
