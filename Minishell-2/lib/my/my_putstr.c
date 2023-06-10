/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** true
*/

#include"prototypes.h"
#include<stdarg.h>

void my_putstr(char const *str, int *result)
{
    int a = 0;
    while (str[a] != '\0') {
        my_putchar_r(str[a], result);
        a++;
    }
}
