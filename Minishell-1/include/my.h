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

#ifndef include
    #define include

typedef struct data_s {

    int status;
    int return_status;
    int i;
    int n;
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

}data_t;


void is_alphanum(char **buffer, char **env, data_t *data);
void print_env(char **env);
void old_pwd(char **buffer, char **env, data_t *data);
int check_oldpwd(char **buffer, char **env, data_t *data);
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
