/*
** EPITECH PROJECT, 2022
** my_s.c
** File description:
** true
*/

#include<stdarg.h>
#include"prototypes.h"

void my_s(int g, int *result)
{
    if (g < 8)
        my_putstr("00", result);
    if (g >= 8 && g < 64 )
        my_putstr("0", result);
}
