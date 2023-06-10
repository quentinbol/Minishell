/*
** EPITECH PROJECT, 2023
** my str
** File description:
** to word array
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "prototypes.h"

int number_word_gen(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != c) &&
            (str[i + 1] == c || str[i + 1] == '\0'))
            count++;
    }
    return (count);
}

char **my_str_to_word_array_gen(char *str, char c)
{
    int i = 0; int a = 0;
    char **tab = malloc(sizeof(char*) * (number_word_gen(str, c) + 1));
    int j = 0; int k = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ')
            i++;
        tab[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
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
