/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** globbing
*/

#ifndef globbing_
    #define globbing_
    #include "minishell.h"

/**
 * @brief structure that store different element for the shell programming
 *
 */
typedef struct mysh_s mysh_t;

/**
 * @brief structure that store different element for globbing
 *
 */
typedef struct globbing_s {

    glob_t glob_result;
    size_t i;
    int j;
    char **new_argv;
    int count;

}globbing_t;

/**
 * @brief function to find if the command is a global command or not
 *
 * @param mysh
 * @param cmd
 * @param final_path
 * @param path
 * @return true
 * @return false
 */
bool find_global_cmd(mysh_t *mysh, char **cmd, char *final_path, char *path);

#endif /* !globbing */
