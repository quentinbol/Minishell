/*
** EPITECH PROJECT, 2022
** mstwa
** File description:
** true
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "prototypes.h"

int number_word(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != ' ' && str[i] != '\t') &&
            (str[i + 1] == ' ' || str[i + 1] == '\t'
            || str[i + 1] == '\0') && (str[i] != '\0'))
            count++;
    }
    return (count);
}

char **my_str_to_word_array(char *str)
{
    int i = 0; int a = 0; int j = 0; int k = 0;
    char **tab = malloc(sizeof(char*) * (number_word(str) + 1));
    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == '\0') break;
        tab[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
        j = 0;
        while (str[i] != ' ' && str[i] != '\t'
                && str[i] != '\0') {
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

int number_word_2(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != '=' && str[i] != '\t') &&
            (str[i + 1] == '=' || str[i + 1] == '\t'
            || str[i + 1] == '\0'))
            count++;
    }
    return (count);
}

char **my_str_to_word_array_2(char *str)
{
    char **tab = malloc(sizeof(char*) * (number_word_2(str) + 1));
    int j = 0; int i = 0; int k = 0;

    while (str[i] != '\0') {
        tab[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
        while (str[i] == '=' || str[i] == '\t')
            i++;
        j = 0;
        while (str[i] != '=' && str[i] != '\t'
                && str[i] != '\0') {
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
