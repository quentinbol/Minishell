/*
** EPITECH PROJECT, 2023
** history.h
** File description:
** histo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <aio.h>
#include <ctype.h>
#include <stdbool.h>
#include <fcntl.h>

#ifndef histo
    #define histo

    /**
     * @brief smaller call for extern
     *
     */
    #define ext_ extern

    /**
     * @brief define for the number of command we can put in the history
     *
     */
    #define MAX_HISTORY_SIZE 21474830

    /**
     * @brief number of path we can stock in a path[TAB]
     *
     */
    #define PATH_MAX        4096

    /**
     * @brief structure to store different element of the history
     *
     */
    typedef struct histo_s {

        char* history[MAX_HISTORY_SIZE];
        int command_number[MAX_HISTORY_SIZE];
        time_t command_time[MAX_HISTORY_SIZE];
        int current_number;
        int history_size;
        char *save;
        bool command_not_found;
        bool done;

    } histo_t;

/**
 * @brief remove the space and a specific char (char c)
 *
 * @param str
 * @param c
 * @return char**
 */
char **my_str_to_word_array_gen(char *str, char c);

/**
 * @brief re write the history after the modification from the other functions
 *
 * @param line
 * @param histo__
 */
void re_write_history(char *line, histo_t *histo__);

/**
 * @brief clear the history
 *
 * @param histo__
 */
void clear_history(histo_t *histo__);

/**
 * @brief main function for history that call all of the other functions
 *
 * @param line
 * @param histo__
 * @return char*
 */
char* history(char *line, histo_t *histo__);

/**
 * @brief utils function to cut a str from the character put in param
 *
 * @param __string_find
 * @param __destroy
 * @return size_t
 */
size_t my_strcspn(const char* __string_find, const char* __destroy);

/**
 * @brief search a character in a string
 *
 * @param __first_str
 * @param index
 * @return char*
 */
char* my_strchr(const char* __first_str, int index);

/**
 * @brief free the history after usage
 *
 * @param histo__
 */
void free_history(histo_t *histo__);

/**
 * @brief function to init the history
 *
 * @param histo__
 * @return histo_t*
 */
histo_t* init_histo(histo_t *histo__);

/**
 * @brief function to update the history after a new command
 *
 * @param line
 * @param histo__
 */
void update_history(char *line, histo_t *histo__);

/**
 * @brief change the index of command after a new command (+1)
 *
 * @param histo__
 * @param i
 */
void change_index_prev(histo_t *histo__, int i);

/**
 * @brief string to the previous in case of too much commands in the history
 *
 * @param line
 * @param histo__
 */
void change_history_string_prev(char *line, histo_t *histo__);

/**
 * @brief delete the duplicate command found in history
 *
 * @param histo__
 * @param duplicate_index
 * @param i
 */
void del_duplicate(histo_t *histo__, int duplicate_index, int i);

/**
 * @brief search for the command duplicate in history
 *
 * @param histo__
 * @param dup_index
 * @param i
 * @param line
 */
void search_duplicate(histo_t *histo__, int *dup_index, int i, char *line);

/**
 * @brief check the exclamation point
 *
 * @param line
 * @param histo__
 * @param index
 * @return ext_*
 */
ext_ char *check_exclamation_point(char *line, histo_t *histo__, int *index);

/**
 * @brief delete the first charater of a string
 *
 * @param str
 * @return ext_*
 */
ext_ char *del_first_char(char *str);

/**
 * @brief main function to update the history
 *
 * @param line
 * @param histo__
 */
ext_ void history_handling(char *line, histo_t *histo__);

/**
 * @brief algo to find a word in history
 *
 * @param line
 * @param histo__
 * @param search_from_letter
 */
ext_ void find_from_word(char *line, histo_t *histo__, bool search_from_letter);

/**
 * @brief algo to find a word from index in history
 *
 * @param line
 * @param histo__
 * @param index
 * @return ext_
 */
ext_ void find_from_index(char *line, histo_t *histo__, int *index);

/**
 * @brief function to check errror
 *
 * @param histo__
 * @param index
 * @return ext_
 */
ext_ void error_history_handling(histo_t *histo__, int index);
#endif /* !histro */
