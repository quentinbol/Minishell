/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** true
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return (a);
}

int my_strlen_array(char** str)
{
    int len = 0;
    for (int i = 0; str[i]; i++) {
        len += my_strlen(str[i]);
    }
    return len;
}
