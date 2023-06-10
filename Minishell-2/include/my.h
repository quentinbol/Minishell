/*
** EPITECH PROJECT, 2023
** include
** File description:
** include
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include "../lib/my/prototypes.h"
#include <fcntl.h>

#ifndef include
    #define include

typedef struct data_s {

    int handled;
    int status;
    int return_status;
    int i;
    int n;
    int count2;
    int count;
    int ok;
    int access;
    char **cmp_env;
    char **final_env;
    char **copy_2;
    char **test;
    char *str_env;
    char *new_string;
    char *new_line2;
    int num_lines;
    int suppression;
    int a;
    int wrong;
    int k;
    char *path;
    int test_i;
    int opt;
    int j;
    int b;
    int c;
    int m;
    char **args;
    int number;
    int double_red;

}data_t;

    #define REMPLACE_FILE O_WRONLY | O_CREAT | O_TRUNC
    #define ADD_TO_FILE O_WRONLY | O_CREAT | O_APPEND

void double_redirect(char **pipe_buff, data_t *data, int j);
void minishell_2(char **buffer, char **env, char *str2, data_t *data);
void if_slash(char **pipe_buff, int i, char **env, data_t *data);
void redirection_handling_2(char *parsing, data_t *data, char **env
                            , char *str2);
void redirection_handling(char **parsing, data_t *data, char **env, char *str2);
void if_wrong_architecture(char **buffer);
int command_not_found_2(char **buffer, char *str2, data_t *data);
void exec_t(char **args, char *str2, data_t *data);
void pipe_handling_2(char** pipe_buff, char **env, data_t *data, char *str2);
void find_path(char **pipe_buff,char **env, data_t *data, int k);
void if_wait(data_t *data, int count);
void separator_handling(char** pipe_buff, char **env, data_t *data, char *str2);
void pipe_handling(char* pipe_buff, char **env, data_t *data, char *str2);
void is_alphanum(char **buffer, char **env, data_t *data);
void print_env(char **env);
void old_pwd(char **buffer, char **env, data_t *data);
int check_oldpwd(char **buffer, char **env, data_t *data, char *old);
int get_line_term(int read, char **copy_env, char *str2, data_t *data);
char **check_env(char **buffer, char **env, data_t *data, char *str2);
char **check_unsetenv(char **buffer, char **final_copy, data_t *data);
char **unsetenv_f(char **buffer, char **final_copy, data_t *data);
char **alloc_new_tab(char *new_string, data_t *data, char **copy_2);
char **replace_tab(char **copy_2, char *new_string, data_t *data, int i);
char** replace_tab_bis(char **copy_2, char **test, char *new_string,
                        data_t *data);
void check_signal(pid_t pid, data_t *data, char **buffer);
void buffer_two_exist(char **buffer, data_t *data, char* new_line2);
void count_line(char **copy_2, data_t *data);
void verif_if_buffer_null(char **copy_2, char **buffer2, char** final_env,
                            data_t *data);
void print_signal(char *sig);
void signal_handler(int signo);
void signal_proc_handler(int signo);
char** set_env(char **buffer2, char **env, data_t *data, char *str2);
void free_all_k(char **copy_env, char *str2);
int executable_handle(char **buffer, char **env, data_t *data);
int cd_handle(char **buffer, char **env, data_t *data);
int pwd(char **buffer, data_t *data);
int start_shell(char **env, data_t *data);
int ls_handle(char **buffer, char **env, data_t *data, char *str2);
int exec(char **buffer, char **env);
int environnement(char **buffer, char **env);
void exit_shell(char **buffer, char **env, char *str2, data_t *data);
int find_number_of_word(char *str2);
void echo(char **buffer, char **env, data_t *data);
int command_not_found(char **buffer, char *str2, char **env, data_t *data);

#endif /* !incl */
