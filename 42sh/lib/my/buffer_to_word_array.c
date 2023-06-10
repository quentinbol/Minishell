/*
** EPITECH PROJECT, 2023
** Compress
** File description:
** Compress Text file
*/

#include "my.h"

int count_words(char *str, char separator)
{
    int c = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == separator || str[i] == '\n' || str[i] == '\t')
        && (str[i + 1] != separator && str[i + 1] != '\n' && str[i + 1] != '\t')
        && str[i + 1] != '\0') {
            c++;
        }
    }
    return (c);
}

static int first_index(char *buffer, char separator)
{
    int i = 0;

    for (; (buffer[i] == separator
    || buffer[i] == '\n'
    || buffer[i] == '\t'); i++);
    return (i);
}

int len_word(char const *str, int i, char separator)
{
    int c = 0;

    for (; str[i] != '\n' && str[i] != separator
    && str[i] != '\t' && str[i] != '\0'; i++) {
        c++;
    }
    return (c);
}

static int create_array_step(array_t *array,
char *buffer, int i, char separator)
{
    if (((buffer[i] == separator || buffer[i] == '\n' || buffer[i] == '\t')
    && (buffer[i + 1] != separator
    && buffer[i + 1] != '\n' && buffer[i + 1] != '\t'))
    && buffer[i + 1] != '\0') {
        array->word[array->k] = '\0';
        array->array[array->n] = array->word;
        array->n += 1;
        array->k = 0;
        array->word = malloc(sizeof(char) *
        (len_word(buffer, i + 1, separator) + 1));
    }
    if (buffer[i] != separator && buffer[i] != '\n' && buffer[i] != '\t') {
        array->word[array->k] = buffer[i];
        array->k += 1;
    }
    return (0);
}

char **buffer_to_word_array(char *buffer, char separator)
{
    array_t array;

    array.array = malloc(sizeof(char *) * (count_words(buffer, separator) + 1));
    array.word = malloc(sizeof(char)
    * (len_word(buffer, first_index(buffer, separator), separator) + 1));
    array.k = 0;
    array.n = 0;
    for (int i = first_index(buffer, separator); buffer[i] != '\0'; i++)
        create_array_step(&array, buffer, i, separator);
    array.word[array.k] = '\0';
    array.array[array.n] = array.word;
    array.array[array.n + 1] = NULL;
    return (array.array);
}
