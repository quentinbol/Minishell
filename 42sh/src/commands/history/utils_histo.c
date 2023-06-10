/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils_histo
*/

#include "history.h"

ext_ char *del_first_char(char *str)
{
    int len = strlen(str);
    if (len > 0) {
        memmove(str, str + 1, len);
    }
    return str;
}

static int number_word_gen(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != c) &&
            (str[i + 1] == c || str[i + 1] == '\0'))
            count++;
    }
    return (count);
}

ext_ char **my_str_to_word_array_gen(char *str, char c)
{
    int i = 0; int j = 0; int k = 0;
    char **tab = NULL;
    tab = malloc(sizeof(char*) * (number_word_gen(str, c) + 1));
    while (str[i] != '\0') {
        while (str[i] == ' ')
            i++;
        tab[k] = malloc(sizeof(char) * (strlen(str) + 1));
        while (str[i] == c)
            i++;
        j = 0;
        while (str[i] != c && str[i] != '\0') {
            tab[k][j] = str[i];
            i++;
            j++;
        }
        tab[k][j] = '\0';
        k++;
    }
    tab[k] = NULL;
    return (tab);
}

ext_ char* my_strchr(const char* __first_str, int index)
{
    while (*(__first_str) != '\0') {
        if (*(__first_str) == index)
            return ((char*)__first_str);
        __first_str++;
    }
    if (*(__first_str) == index) {
        return ((char*)__first_str);
    }
    return NULL;
}

size_t my_strcspn(const char* __string_find, const char* __destroy)
{
    size_t f_instance = 0;

    for (f_instance = 0; __string_find[f_instance] != '\0'; f_instance++) {
        if (my_strchr(__destroy, __string_find[f_instance]) != NULL) {
            return f_instance;
        }
    }
    return f_instance;
}
