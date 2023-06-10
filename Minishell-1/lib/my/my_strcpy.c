/*
** EPITECH PROJECT, 2022
** my_strcpy.c
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

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}

char** my_copy_char_array(char** source)
{
    int length = 0;
    while (source[length] != NULL) {
        length++;
    }
    char** copy = malloc(sizeof(char*) * (length + 1));
    for (int i = 0; i < length; i++) {
        int str_length = my_strlen(source[i]);
        copy[i] = malloc(sizeof(char) * (str_length + 1));
        my_strcpy(copy[i], source[i]);
    }
    copy[length] = NULL;

    return copy;
}
