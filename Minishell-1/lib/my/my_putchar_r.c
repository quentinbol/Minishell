/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** true
*/

#include<unistd.h>
#include<stdarg.h>

void my_putchar_r(char c, int *result)
{
    write(1, &c, 1);
    (*result)++;
}
