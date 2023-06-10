/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** dup
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "prototypes.h"

char *my_strdup(char const *src)
{
    int stop;
    char *copy;
    int i = 0;

    copy = malloc(sizeof(char) * (my_strlen(src)));
    while (src[i] != '\0') {
        copy[i] = src[i];
        i++;
    }
    stop = my_strlen(copy);
    copy[stop] = '\0';
    return copy;
}

int est_espace(char c)
{
    return (c == ' ' || c == '\t');
}

char *delete_space(char *rev_cop, char *copy)
{
    rev_cop = my_evil_str(copy);
    char* beg = rev_cop;
    while (est_espace(*beg)) {
        ++beg;
    }
    if (beg != rev_cop) {
        char* end = rev_cop;
        while (*beg) {
            *(end++) = *(beg++);
        }
        *end = '\0';
    }
    my_evil_str(rev_cop);
    return rev_cop;
}

char *my_strdup_shell(char *src)
{
    int stop;
    char *rev_cop;
    char *copy;
    int i = 0;
    int j = 0;
    int count = 0;
    int lenght = my_strlen(src) - 1;
    lenght = lenght - j + count;
    copy = malloc(sizeof(char) * (my_strlen(src) - 1));
    while (i != lenght) {
            copy[i] = src[i];
            i++;
    }
    return delete_space(rev_cop, copy);
}

char *my_strdup_shell_2(char *src)
{
    int stop;
    char *copy;
    int i = 0;
    int j = 0;
    int count;
    int lenght = my_strlen(src) - 1;

    count = number_word(src);
    for (int i = 0; src[i]; i++)
        if (src[i] == '\t' || src[i] == ' ')
            j++;
    lenght = lenght - j;
    copy = malloc(sizeof(char) * (my_strlen(src) - 1));
    while (i != lenght) {
            copy[i] = src[i];
            i++;
    }
    copy[lenght] = '\0';
    return copy;
}
