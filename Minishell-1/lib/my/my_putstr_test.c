/*
** EPITECH PROJECT, 2022
** my_putstr_test.c
** File description:
** true
*/

#include"prototypes.h"
#include<stdarg.h>

void my_putstr_test(char const *str)
{
    int a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
}
